class Error;
class MapTable;
class StrPtr;
class StrBuf;
class StrArray;

enum MapType { MapInclude, MapExclude, MapOverlay, MapOneToMany };
enum MapDir  { MapLeftRight, MapRightLeft };
enum MapCase { Sensitive, Insensitive };

class MapApi
{
public:
	MapApi(void);
	~MapApi(void);

	//Functions for getting the contents of the mapping.
	int            Count();
	const StrPtr*  GetLeft ( int i );
	const StrPtr*  GetRight( int i );
	MapType        GetType ( int i );

	//Functions for changing the contents of the mapping.
	void Clear();
	void Insert( const StrPtr& lr,                 MapType t = MapInclude );
	void Insert( const StrPtr& l, const StrPtr& r, MapType t = MapInclude );
	void SetCaseSensitivity( MapCase mode );

	//Functions for doing interesting things with the mapping.
	int Translate( const StrPtr& from, StrBuf& to, MapDir d = MapLeftRight );
	int Translate( const StrPtr& from, StrArray& to, MapDir d = MapLeftRight );

	static MapApi* Join( MapApi* left, MapApi* right )
		{ return Join( left, MapLeftRight, right, MapLeftRight ); }
	static MapApi* Join( MapApi* m1, MapDir d1, MapApi* m2, MapDir d2 );

	static void Validate( const StrPtr& path, Error* e );

private:
	MapTable* table;
	MapApi( MapTable* t );
	void Init();

	int ambiguous;
	void Disambiguate();
};
