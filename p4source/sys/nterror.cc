/*
 * Copyright 1995, 1996 Perforce Software.  All rights reserved.
 *
 * This file is part of Perforce - the FAST SCM System.
 */

// Socket errors for NT
// nt_sock_errlist is used for WSABASEERR + 1 to 112, contains a 0th entry
const char *nt_sock_errlist[] =
{
	"NO_ERROR", // WSABASEERR + 0
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSAEINTR", // WSABASEERR + 4
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSAEBADF",  //9
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSAEACCES",  //13
	"WSAEFAULT", //14
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSAEINVAL",  //22
	"NO_ERROR",
	"WSAEMFILE",  //24
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSAEWOULDBLOCK", //35
	"WSAEINPROGRESS", //36
	"WSAEALREADY", //37
	"WSAENOTSOCK", //38
	"WSAEDESTADDRREQ", //39
	"WSAEMSGSIZE", //40
	"WSAEPROTOTYPE", //41
	"WSAENOPROTOOPT", //42
	"WSAEPROTONOSUPPORT", //43
	"WSAESOCKTNOSUPPORT", //44
	"WSAEOPNOTSUPP", //45
	"WSAEPFNOSUPPORT", //46
	"WSAEAFNOSUPPORT", //47
	"WSAEADDRINUSE", //48
	"WSAEADDRNOTAVAIL", //49
	"WSAENETDOWN", //50
	"WSAENETUNREACH", //51
	"WSAENETRESET", //52
	"WSAECONNABORTED", //53
	"WSAECONNRESET", //54
	"WSAENOBUFS", //55
	"WSAEISCONN", //56
	"WSAENOTCONN", //57
	"WSAESHUTDOWN", //58
	"WSAETOOMANYREFS", //59
	"WSAETIMEDOUT", //60
	"WSAECONNREFUSED", //61
	"WSAELOOP", //62
	"WSAENAMETOOLONG", //63
	"WSAEHOSTDOWN", //64
	"WSAEHOSTUNREACH", //65
	"WSAENOTEMPTY", //66
	"WSAEPROCLIM", //67
	"WSAEUSERS", //68
	"WSAEDQUOT", //69
	"WSAESTALE", //70
	"WSAEREMOTE", //71
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSASYSNOTREADY", //91
	"WSAVERNOTSUPPORTED", //92
	"WSANOTINITIALISED", //93
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"NO_ERROR",
	"WSAEDISCON", //101
	"WSAENOMORE", //102
	"WSAECANCELLED", //103
	"WSAEINVALIDPROCTABLE", //104
	"WSAEINVALIDPROVIDER", //105
	"WSAEPROVIDERFAILEDINIT", //106
	"WSASYSCALLFAILURE", //107
	"WSASERVICE_NOT_FOUND", //108
	"WSATYPE_NOT_FOUND", //109
	"WSA_E_NO_MORE", //110
	"WSA_E_CANCELLED", //111
	"WSAEREFUSED" //112
};

const char *nt_sock_errlist2[] = // for WSABASEERR + 1001 to 1033
{
	"WSAHOST_NOT_FOUND", //WSABASEERR + 1001
	"WSATRY_AGAIN", //1002
	"WSANO_RECOVERY", //1003
	"WSANO_DATA", //1004
	"WSA_QOS_RECEIVERS", //1005
	"WSA_QOS_SENDERS", //1006
	"WSA_QOS_NO_SENDERS", //1007
	"WSA_QOS_NO_RECEIVERS", //1008
	"WSA_QOS_REQUEST_CONFIRMED", //1009
	"WSA_QOS_ADMISSION_FAILURE", //1010
	"WSA_QOS_POLICY_FAILURE", //1011
	"WSA_QOS_BAD_STYLE", //1012
	"WSA_QOS_BAD_OBJECT", //1013
	"WSA_QOS_TRAFFIC_CTRL_ERROR", //1014
	"WSA_QOS_GENERIC_ERROR", //1015
	"WSA_QOS_ESERVICETYPE", //1016
	"WSA_QOS_EFLOWSPEC", //1017
	"WSA_QOS_EPROVSPECBUF", //1018
	"WSA_QOS_EFILTERSTYLE", //1019
	"WSA_QOS_EFILTERTYPE", //1020
	"WSA_QOS_EFILTERCOUNT", //1021
	"WSA_QOS_EOBJLENGTH", //1022
	"WSA_QOS_EFLOWCOUNT", //1023
	"WSA_QOS_EUNKOWNPSOBJ", //1024
	"WSA_QOS_EPOLICYOBJ", //1025
	"WSA_QOS_EFLOWDESC", //1026
	"WSA_QOS_EPSFLOWSPEC", //1027
	"WSA_QOS_EPSFILTERSPEC", //1028
	"WSA_QOS_ESDMODEOBJ", //1029
	"WSA_QOS_ESHAPERATEOBJ", //1030
	"WSA_QOS_RESERVED_PETYPE", //1031
	"WSA_SECURE_HOST_NOT_FOUND", //1032
	"WSA_IPSEC_NAME_POLICY_ERROR" //1033
};