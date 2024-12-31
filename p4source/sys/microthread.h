/*
 * Copyright 1995, 2022 Perforce Software.  All rights reserved.
 *
 * This file is part of Perforce - the FAST SCM System.
 */

class MicroThreadPool;

class MicroThread {
    public:
	                MicroThread();
	virtual         ~MicroThread();
	int             RunWork();
	Error           &ErrorObj() { return err; }
	void            Wait();
	bool            Started();
	bool            Running() const { return running; }
	void            SetPool( MicroThreadPool *p ) { pool = p; }
	void            SwitchThread( MicroThread * );

    protected:
	virtual void    Work();
	virtual void    PostWork();

    private:
	static void     WorkLaunch( void * );

	Error           err;
# ifdef HAVE_THREAD
	std::thread     mythread;
	std::mutex      mymutex;
# endif
	volatile bool   started, running, joined, postrun, waiton;
	MicroThreadPool *pool;
	P4DebugConfig   *dbgconfig;
} ;

class MicroThreadMutex {
    public:
	MicroThreadMutex() {}
	virtual ~MicroThreadMutex() {};

	void GetMutex();
	void ReleaseMutex();

# ifdef HAVE_THREAD
    private:
	std::mutex      mutex;
# endif
} ;

class MicroThreadPool {
    public:
	                  MicroThreadPool() : activeLimit( 0 ),
	                                      skiponerror( 0 ) {}
	virtual           ~MicroThreadPool() { WaitAll(); }
	void              ThreadLimit( int n );
	int               GetThreadLimit();
	void              AddThread( MicroThread * );
	void              WaitAll( Error * = 0 );
	void              Reap( Error * = 0 );
	MicroThread       *NextWork();
	MicroThreadMutex  &PoolMutex() { return poolMutex; }
	int               IsSkipOnError() { return skiponerror; }
	void              SetSkipOnError() { skiponerror = 1; }
    private:
	void StartWaiting();

	int      activeLimit;
	VarArray active;
	VarArray waiting;
	MicroThreadMutex poolMutex;
	int      skiponerror;
} ;

// Helper to guess threads when threads == 0
int ThreadGuess(int tcount);
