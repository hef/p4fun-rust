/*
 * Copyright 1995, 2000 Perforce Software.  All rights reserved.
 *
 * This file is part of Perforce - the FAST SCM System.
 */

/*
 * msgspec.cc - definitions of errors for info subsystem.
 *
 * Note:
 *
 * Never re-use an error code value,  these may have already been 
 * translated, so using it for a different error is not OK.
 *
 * ErrorIds which are no longer used should be moved to the bottom
 * of the list, with a trailing comment like this: // DEPRECATED.
 * We keep these to maintain compatibility between newer api clients
 * and older servers which send old ErrorIds.
 *
 * Its okay to add a message in the middle of the file.
 *
 * When adding a new error make sure its greater than the current high
 * value and update the following number:
 *
 * Current high value for a MsgSpec error code is: 21
 */
# include <stdhdrs.h>
# include <error.h>
# include <errornum.h>
# include "msgspec.h"

ErrorId MsgSpec::SpecBranch = { ErrorOf( ES_SPEC, 1, E_INFO, EV_NONE, 0  ), 
"# A %'Perforce Branch'% Specification.\n"
"#\n"
"#  %'Branch'%:      The branch name.\n"
"#  %'Update'%:      The date this specification was last modified.\n"
"#  %'Access'%:      The date of the last '%'integrate'%' using this branch.\n"
"#  %'Owner'%:       The user who created this branch.\n"
"#  %'Description'%: A short description of the branch (optional).\n"
"#  %'Options'%:     Branch update options: %'[un]locked'%.\n"
"#  %'View'%:        Lines to map source depot files to target depot files.\n"
"#\n"
"# Use '%'p4 help branch'%' to see more about branch views.\n" };

ErrorId MsgSpec::SpecClient = { ErrorOf( ES_SPEC, 2, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Client'% Specification.\n"
"#\n"
"#  %'Client'%:      The client name.\n"
"#  %'Update'%:      The date this specification was last modified.\n"
"#  %'Access'%:      The date this client was last used in any way.\n"
"#  %'Owner'%:       The %'Perforce'% user name of the user who owns the client\n"
"#               workspace. The default is the user who created the\n"
"#               client workspace.\n"
"#  %'Host'%:        If set, restricts access to the named host.\n"
"#  %'Description'%: A short description of the client (optional).\n"
"#  %'Root'%:        The base directory of the client workspace.\n"
"#  %'AltRoots'%:    Up to two alternate client workspace roots.\n"
"#  %'Options'%:     Client options:\n"
"#                      %'[no]allwrite [no]clobber [no]compress'%\n"
"#                      %'[un]locked [no]modtime [no]rmdir [no]altsync'%\n"
"#  %'SubmitOptions'%:\n"
"#                      %'submitunchanged/submitunchanged+reopen'%\n"
"#                      %'revertunchanged/revertunchanged+reopen'%\n"
"#                      %'leaveunchanged/leaveunchanged+reopen'%\n"
"#  %'LineEnd'%:     Text file line endings on client: %'local/unix/mac/win/share'%.\n"
"#  %'Type'%:        Type of client: %'writeable/readonly/graph/partitioned/'%\n"
"#                                   %'partitioned-jnl'%.\n"
"#  %'ServerID'%:    If set, restricts access to the named server.\n"
"#  %'View'%:        Lines to map depot files into the client workspace.\n"
"#  %'ChangeView'%:  Lines to restrict depot files to specific changelists.\n"
"#  %'Stream'%:      The stream to which this client's view will be dedicated.\n"
"#               (Files in stream paths can be submitted only by dedicated\n"
"#               stream clients.) When this optional field is set, the\n"
"#               View field will be automatically replaced by a stream\n"
"#               view as the client spec is saved.\n"
"#  %'StreamAtChange'%:  A changelist number that sets a back-in-time view of a\n"
"#                   stream ( %'Stream'% field is required ).\n"
"#                   Changes cannot be submitted when this field is set.\n"
"#\n"
"# Use '%'p4 help client'%' to see more about client views and options.\n" };

ErrorId MsgSpec::SpecStream = { ErrorOf( ES_SPEC, 14, E_INFO, EV_NONE, 0 ),
"# A %'Perforce Stream'% Specification.\n"
"#\n"
"#  %'Stream'%:       The %'stream'% field is unique and specifies the depot path.\n"
"#  %'Update'%:       The date the specification was last changed.\n"
"#  %'Access'%:       The date the specification was originally created.\n"
"#  %'Owner'%:        The user who created this stream.\n"
"#  %'Name'%:         A short title which may be updated.\n"
"#  %'Parent'%:       The parent of this stream, or '%'none'%' if %'Type'% is mainline.\n"
"#  %'Type'%:         Type of stream provides clues for commands run\n"
"#                between stream and parent.  Seven types include '%'mainline'%',\n"
"#                '%'development'%' (default), '%'release'%', '%'sparsedev'%',\n"
"#                '%'sparserel'%', '%'task'%', and '%'virtual'%'.\n"
"#  %'Description'%:  A short description of the stream (optional).\n" 
"#  %'Options'%:      Stream Options:\n" 
"#                       %'allsubmit/ownersubmit [un]locked'%\n"
"#                       %'[no]toparent [no]fromparent mergedown/mergeany'%\n"
"#  %'ParentView'%:   Whether the stream spec inherits a view from its parent:\n" 
"#                %'inherit/noinherit'%.\n"
"#  %'Components'%:   Incorporate component stream paths into this stream and\n"
"#                define the view mappings for the clients of this stream.\n"
"#  %'Paths'%:        Identify paths in the stream and how they are to be\n" 
"#                generated in resulting clients of this stream.\n"
"#                Path types are %'share/isolate/import/import+/exclude'%.\n"
"#  %'Remapped'%:     Remap a stream path in the resulting client view.\n" 
"#  %'Ignored'%:      Ignore a stream path in the resulting client view.\n" 
"#\n" 
"# Use '%'p4 help stream'%' to see more about stream specifications and command.\n"  };

ErrorId MsgSpec::SpecLabel = { ErrorOf( ES_SPEC, 3, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Label'% Specification.\n"
"#\n"
"#  %'Label'%:       The label name.\n"
"#  %'Update'%:      The date this specification was last modified.\n"
"#  %'Access'%:      The date of the last '%'labelsync'%' on this label.\n"
"#  %'Owner'%:       The user who created this label.\n"
"#  %'Description'%: A short description of the label (optional).\n"
"#  %'Options'%:     Label update options: %'[un]locked, [no]autoreload'%.\n"
"#  %'Revision'%:    Optional revision specification to make an automatic label.\n"
"#  %'ServerID'%:    If set, restricts access to the named server.\n"
"#  %'View'%:        Lines to select depot files for the label.\n"
"#\n"
"# Use '%'p4 help label'%' to see more about label views.\n" };

ErrorId MsgSpec::SpecLdap = { ErrorOf( ES_SPEC, 16, E_INFO, EV_NONE, 0 ),
"# A %'Perforce Ldap'% Configuration Specification.\n"
"#\n"
"#  %'Name'%:          The %'LDAP'% configuration name.\n"
"#  %'Host'%:          The %'FQDN'% of the directory server.\n"
"#  %'Port'%:          The port number on which to connect to the directory server.\n"
"#  %'Encryption'%:    The encryption method to use when connecting to the\n"
"#                 directory server. Options are: '%'none'%', '%'ssl'%' and '%'tls'%'.\n"
"#  %'BindMethod'%:    The bind method to use with this directory. Options are:\n"
"#                 '%'simple'%', '%'search'%' and '%'sasl'%'.\n"
"#  %'Options'%:       LDAP Options:\n"
"#                     %'[no]downcase [no]getattrs [no]realminusername'%\n"
"#\n"
"#  The following field only applies to the '%'simple'%' bind method.\n"
"#\n"
"#  %'SimplePattern'%: This is the %'DN'% which will be used to bind against to\n"
"#                 validate the user's credentials. The %%%'user'%%% placeholder\n"
"#                 will be replaced with the user's userId.\n"
"#\n"
"#  The following fields only apply to the '%'search'%' bind method; however they\n"
"#  may also be used by '%'p4 ldapsync'%' and for user creation with '%'p4 login'%'.\n"
"#\n"
"#  %'SearchBaseDN'%:  The %'DN'% from which to start the search for the user object.\n"
"#  %'SearchFilter'%:  The %'LDAP'% query filter to use to identify the user object\n"
"#                 which will be used to bind against. The %%%'user'%%% placeholder\n"
"#                 will be replaced with the user's userId.\n"
"#  %'SearchScope'%:   The scope to use when searching for the user records.\n"
"#  %'               Options are'%:\n"
"#                         %'baseonly'% - Just the %'BaseDN'% object\n"
"#                         %'children'% - The %'BaseDN'% and its direct children\n"
"#                         %'subtree'% - The %'BaseDN'% and all objects below it\n"
"#  %'SearchBindDN'%:  The %'DN'% to bind against in order to search the directory.\n"
"#  %'SearchPasswd'%:  The password for the %'BindDN'% record.\n"
"#\n"
"#  The following field only applies to the '%'sasl'%' bind method.\n"
"#\n"
"#  %'SaslRealm'%: The optional realm to use when authenticating the user via %'SASL'%.\n"
"#\n"
"#  The following fields are related to group membership within the directory.\n"
"#  Set '%'GroupSearchFilter'%' if users must belong to a specific group within\n"
"#  the directory. The remaining two fields may also be used by '%'p4 ldapsync'%'.\n"
"#\n"
"#  %'GroupSearchFilter'%: The filter to use for the group search.\n"
"#  %'GroupBaseDN'%:       The search base for performing the group search. If unset\n"
"#                     this will default to the %'SearchBaseDN'%.\n"
"#  %'GroupSearchScope'%:  The scope to use when performing the group search.\n"
"#                     Options are:\n"
"#                             %'baseonly'% - Just the %'BaseDN'% object\n"
"#                             %'children'% - The %'BaseDN'% and its direct children\n"
"#                             %'subtree'% - The %'BaseDN'% and all objects below it\n"
"#\n"
"#  The following fields are used to populate new user specifications created\n"
"#  with '%'p4 login'%' when the '%'auth.ldap.userautocreate'%' configurable is set\n"
"#  to to 1 and the '%'getattrs'%' option is enabled.\n"
"#\n"
"#  %'AttributeUid'%:      The name of the attribute in the directory's user\n"
"#                     records that contain the users' UIDs.\n"
"#  %'AttributeName'%:     The name(s) of the attribute(s) in the directory's user\n"
"#                     records that contain the users' full names.\n"
"#  %'AttributeEmail'%:    The name of the attribute in the directory's user\n"
"#                     records that contain the users' email addresses.\n"
"#\n"
"# Use '%'p4 help ldap'%' to see more about ldap specification.\n" };

ErrorId MsgSpec::SpecLicense = { ErrorOf( ES_SPEC, 13, E_INFO, EV_NONE, 0  ),
"# A %'Perforce License'% Specification.\n"
"#\n"
"#  %'License'%:         The license key.\n"
"#  %'License-Expires'%: Date at which the license expires.\n"
"#  %'Support-Expires'%: Date at which support expires.\n"
"#  %'Customer'%:        Customer to whom this license is granted.\n"
"#  %'Application'%:     Application that can use this license.\n"
"#  %'IPAddress'%:       %'IP/Port'% address for license.\n"
"#  %'Platform'%:        Platform.\n"
"#  %'Clients'%:         Number of supported clients.\n"
"#  %'Users'%:           Number of supported users.\n"
"#\n"
"# Use '%'p4 help license'%' to see more about license specification.\n" };

ErrorId MsgSpec::SpecChange = { ErrorOf( ES_SPEC, 4, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Change'% Specification.\n"
"#\n"
"#  %'Change'%:      The change number. '%'new'%' on a new changelist.\n"
"#  %'Date'%:        The date this specification was last modified.\n"
"#  %'Client'%:      The client on which the changelist was created.  Read-only.\n"
"#  %'User'%:        The user who created the changelist.\n"
"#  %'Status'%:      Either '%'pending'%' or '%'submitted'%'. Read-only.\n"
"#  %'Type'%:        Either '%'public'%' or '%'restricted'%'. Default is '%'public'%'.\n"
"#  %'Description'%: Comments about the changelist.  Required.\n"
"#  %'ImportedBy'%:  The user who fetched or pushed this change to this server.\n"
"#  %'Identity'%:    Identifier for this change.\n"
"#  %'Jobs'%:        What opened jobs are to be closed by this changelist.\n"
"#               You may delete jobs from this list.  (New changelists only.)\n"
"#  %'Stream'%:      What opened stream is to be added to this changelist.\n"
"#               You may remove an opened stream from this list.\n"
"#  %'Files'%:       What opened files from the default changelist are to be added\n"
"#               to this changelist.  You may delete files from this list.\n"
"#               (New changelists only.)\n" };

ErrorId MsgSpec::SpecDepot = { ErrorOf( ES_SPEC, 5, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Depot'% Specification.\n"
"#\n"
"#  %'Depot'%:       The name of the depot.\n"
"#  %'Owner'%:       The user who created this depot.\n"
"#  %'Date'%:        The date this specification was last modified.\n"
"#  %'Description'%: A short description of the depot (optional).\n"
"#  %'Type'%:        Whether the depot is '%'local'%', '%'remote'%',\n"
"#               '%'stream'%', '%'spec'%', '%'archive'%', '%'tangent'%',\n"
"#               '%'unload'%', '%'extension'%', '%'trait'%' or '%'graph'%'.\n"
"#               Default is '%'local'%'.\n"
"#  %'Address'%:     Connection address.\n"
"#  %'Suffix'%:      Suffix for all saved specs (spec depot only).\n"
"#  %'StreamDepth'%: Depth for streams in this depot (stream depots only).\n"
"#  %'Map'%:         Path translation information (must have %'...'% in it).\n"
"#  %'SpecMap'%:     For %'spec'% depot, which specs should be recorded (optional).\n"
"#\n"
"# Use '%'p4 help depot'%' to see more about depot forms.\n" };

ErrorId MsgSpec::SpecGroup = { ErrorOf( ES_SPEC, 6, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Group'% Specification.\n"
"#\n"
"#  %'Group'%:       The name of the group.\n"
"#  %'Description'%: A description for the group (optional).\n"
"#  %'MaxResults'%:  Limits the rows (unless '%'unlimited'%' or '%'unset'%') any one\n"
"#               operation can return to the client.\n"
"#               See '%'p4 help maxresults'%'.\n"
"#  %'MaxScanRows'%: Limits the rows (unless '%'unlimited'%' or '%'unset'%') any one\n"
"#               operation can scan from any one database table.\n"
"#               See '%'p4 help maxresults'%'.\n"
"#  %'MaxLockTime'%: Limits the time (in milliseconds, unless '%'unlimited'%' or\n"
"#               '%'unset'%') any one operation can lock any database table when\n"
"#               scanning data. See '%'p4 help maxresults'%'.\n"
"#  %'MaxOpenFiles'%:\n"
"#               Limits files (unless '%'unlimited'%' or '%'unset'%') any one\n"
"#               operation can open. See '%'p4 help maxresults'%'.\n"
"#  %'MaxMemory'%:\n"
"#               Limits the amount of memory a command may consume.\n"
"#               Unit is megabytes.  See '%'p4 help maxresults'%'.\n"
"#  %'Timeout'%:     A time (in seconds, unless '%'unlimited'%' or '%'unset'%')\n"
"#               which determines how long a '%'p4 login'%'\n"
"#               session ticket remains valid (default is 12 hours).\n"
"#  %'PasswordTimeout'%:\n"
"#               A time (in seconds, unless '%'unlimited'%' or '%'unset'%')\n"
"#               which determines how long a '%'p4 password'%'\n"
"#               password remains valid (default is unset).\n"
"#  %'LdapConfig'%:  The LDAP configuration to use when populating the group's\n"
"#               user list from an LDAP query. See '%'p4 help ldap'%'.\n"
"#  %'LdapSearchQuery'%:\n"
"#               The LDAP query used to identify the members of the group.\n"
"#  %'LdapUserAttribute'%:\n"
"#               The LDAP attribute that represents the user's username.\n"
"#  %'LdapUserDNAttribute'%:\n"
"#               The LDAP attribute in the group object that contains the\n"
"#               DN of the user object.\n"
"#  %'Subgroups'%:   Other groups automatically included in this group.\n"
"#  %'Owners'%:      Users allowed to change this group without requiring super\n"
"#               access permission.\n"
"#  %'Users'%:       The users in the group.  One per line.\n" };

ErrorId MsgSpec::SpecProtect = { ErrorOf( ES_SPEC, 7, E_INFO, EV_NONE, 0  ),
"# %'Perforce Protections'% Specification.\n"
"#\n"
"#  %'SubPath'%:     The root path of the sub-protections table (only used when\n"
"#               editing a sub-protections table).\n"
"#\n"
"#  %'Update'%:      The date this specification was last modified (read-only).\n"
"#\n"
"#  %'Protections'%:\n"
"#      Each line contains a protection mode, a group/user indicator, the\n"
"#      group/user name, client host id and a depot file path pattern.\n"
"#      A user gets the highest privilege granted on any line.\n"
"#\n"
"#      %'Mode'%:    The permission level or right being granted or denied.  Each\n"
"#               permission level includes all the permissions above it, except\n"
"#               for '%'review'%' and '%'owner'%'.  Each permission right only includes\n"
"#               the specific right and not all the lesser rights. Modes\n"
"#               preceded by '=' are rights; all other modes are levels.\n"
"#\n"
"#               %'list'%   - users can see names but not contents of files;\n"
"#                        users can see all non-file related metadata\n"
"#                        (%'clients'%, %'users'%, %'changelists'%, %'jobs'%, etc.)\n"
"#\n"
"#               %'read'%   - users can %'sync'%, %'diff'%, and %'print'% files\n"
"#\n"
"#               %'open'%   - users can %'add'%, %'edit'%, %'delete'%, and %'integrate'% files\n"
"#\n"
"#               %'write'%  - users can %'submit'% open files\n"
"#\n"
"#               %'admin'%  - permits those administrative commands and command\n"
"#                        options that don't affect the server's security\n"
"#\n"
"#               %'owner'%  - allows access to the '%'p4 protect'%' command, for\n"
"#                        the specified path.\n"
"#\n"
"#               %'super'%  - allows access to the '%'p4 protect'%' command\n"
"#\n"
"#               %'review'% - allows access to the '%'p4 review'%' command; implies\n"
"#                        read access\n"
"#\n"
"#               %'=read'%  - if this right is denied, users cannot sync, diff,\n"
"#                        or print files\n"
"#\n"
"#               %'=branch'% - if this right is denied, users are not permitted\n"
"#                         to use files as a source for '%'p4 integrate'%'\n"
"#\n"
"#               %'=open'%   - if this right is denied, users cannot open files\n"
"#                         (%'add'%, %'edit'%, %'delete'%, %'integrate'%)\n"
"#\n"
"#               %'=write'%  - if this right is denied, users cannot submit open\n"
"#                         files\n"
"#\n"
"#               %'readstreamspec'%  - users can display a stream spec with\n"
"#                                 with '%'p4 stream -o'%'.\n"
"#\n"
"#               %'openstreamspec'%  - users can revert, resolve, shelve, or\n"
"#                                 open for edit a stream spec\n"
"#\n"
"#               %'writestreamspec'%  - users can submit or modify a stream\n"
"#                                 spec\n"
"#\n"
"#               %'=readstreamspec'%  - if this right is denied, users cannot\n"
"#                                  execute '%'p4 stream -o'%'\n"
"#\n"
"#               %'=openstreamspec'%  - if this right is denied, users cannot\n"
"#                                  revert, resolve, shelve, or open for edit\n"
"#                                  a stream spec\n"
"#\n"
"#               %'=writestreamspec'%  - if this right is denied, users cannot\n"
"#                                   submit or modify a stream\n"
"#\n"
"#      %'Group/User'% indicator: either '%'group'%' or '%'user'%'.\n"
"#\n"
"#      %'Name'%:    A %'Perforce'% group or user name; may be wildcarded.\n"
"#\n"
"#      %'Host'%:    The %'IP'% address of a client host (IPv6 and IPv4 addresses\n"
"#               supported); may be wildcarded, or may instead use %'CIDR'% syntax,\n"
"#               e.g. %'172.16.0.0/16'% would match all %'IPv4'% addresses which\n"
"#               start with %'172.16'%.\n"
"#\n"
"#      %'Path'%:    The part of the depot being granted access.\n" };

ErrorId MsgSpec::SpecServer = { ErrorOf( ES_SPEC, 15, E_INFO, EV_NONE, 0  ), 
"# A %'Perforce Server'% Specification.\n"
"#\n"
"#  %'ServerID'%:    The server identifier.\n"
"#  %'Type'%:        The server type: %'server'%/%'broker'%/%'proxy'%/\n"
"#                   %'connector'%\n"
"#  %'Name'%:        The %'P4NAME'% used by this server (optional).\n"
"#  %'Address'%:     The %'P4PORT'% used by this server (optional).\n"
"#  %'ExternalAddress'%:\n"
"#               For an edge server, this optional field contains its\n"
"#               external address for connections from the commit server.\n"
"#               This field is required for distributed parallel submit.\n"
"#  %'UpdateCachedRepos'%:\n"
"#               For a git-connector, this optional field contains a\n"
"#               list of graph repos which will be updated from Helix\n"
"#               by 'gconn poll-repos', typically called by a cron process.\n"
"#  %'Description'%: A short description of the server (optional).\n"
"#  %'Services'%:    Services provided by this server.\n"
"#               One of the following (grouped by server type):\n"
"#        Type %''server''%:\n"
"#               %'standard'%: standard %'Perforce'% server\n"
"#               %'replica'%: read-only replica server\n"
"#               %'commit-server'%: central server in distributed installation\n"
"#               %'edge-server'%: node in distributed installation\n"
"#               %'forwarding-replica'%: replica which forwards update commands\n"
"#               %'build-server'%: replica which supports build farm integration\n"
"#               %'P4AUTH'%: server which provides central authentication\n"
"#               %'P4CHANGE'%: server which provides central change numbers\n"
"#               %'standby'%: read-only replica server which uses %'journalcopy'%\n"
"#               %'forwarding-standby'%: forwarding-replica which uses %'journalcopy'%\n"
"#               %'local'%: personal server created by %'init'%\n"
"#               %'distribution-server'%: content distribution server\n"
"#        Type %''broker''%:\n"
"#               %'broker'%: %'p4broker'% process\n"
"#        Type %''proxy''%:\n"
"#               %'proxy'%: %'p4p'% caching proxy\n"
"#        Type %''connector''%:\n"
"#               %'git-connector'%: %'p4gconn'% caching proxy\n"
"#\n"
"#  %'Options'%:     Server options: %'[no]mandatory'%.\n"
"#  %'ReplicatingFrom'%:\n"
"#               Server ID of the server from which this server is\n"
"#               replicating or %'journalcopy'ing'%. This field is required\n"
"#               when the server is a %'standby'% or %'forwarding-standby'%\n"
"#               server and the %'mandatory'% option is set for either.\n"
"#  %'User'%:        The service user which will be used by this server\n"
"#  %'AllowedAddresses'%:\n"
"#               A list of addresses that are valid this server.  At security\n"
"#               level 6 this field is used to associate intermediary\n"
"#               servers with specified service users.  Connections through\n"
"#               intermediary servers without matching server specs will be\n"
"#               blocked.\n"
"#  %'ClientDataFilter'%:\n"
"#               For a replica server, this optional field can contain one\n"
"#               or more patterns describing how active client data is to\n"
"#               be filtered. Active client data includes have lists,\n"
"#               working records, and pending resolves.\n"
"#  %'RevisionDataFilter'%:\n"
"#               For a replica server, this optional field can contain one\n"
"#               or more patterns describing how submitted revision data is\n"
"#               to be filtered. Submitted revision data includes revision\n"
"#               records, integration records, label contents, and the files\n"
"#               listed in submitted changelists.\n"
"#  %'ArchiveDataFilter'%:\n"
"#               For a replica server, this optional field can contain one\n"
"#               or more patterns describing the policy for automatically\n"
"#               scheduling the replication of file content. If this field\n"
"#               is present, only those files described by the pattern are\n"
"#               automatically transferred to the replica; other files will\n"
"#               not be transferred until they are referenced by a replica\n"
"#               command which needs the file content.\n"
"#  %'DistributedConfig'%:\n"
"#               This optional field shows configuration settings relevant\n"
"#               to this server. When invoked with the -c flag, the\n"
"#               configuration values are populated with currently\n"
"#               configured values, recommended default values if unset,\n"
"#               or 'unset' for unset values with no default. If this\n"
"#               field is present when invoked with -c, the configuration\n"
"#               commands in this field are run on the current server\n"
"#               using the scope of the ServerID server.\n"
"#\n"
"# Use '%'p4 help server'%' to see more about server ids, services, and options.\n" };

ErrorId MsgSpec::SpecTrigger = { ErrorOf( ES_SPEC, 8, E_INFO, EV_NONE, 0  ),
"# %'Perforce Submit'% and Form Validating Trigger Specifications.\n"
"#\n"
"#  %'Triggers'%:	a list of triggers; one per line. Each trigger line must be\n"
"#		indented with spaces or tabs in the form. Each line has four\n"
"#		elements:\n"
"#\n"
"#  		%'Name'%:   The name of the trigger.\n"
"#\n"
"#  		%'Type'%:   '%'archive'%'	  external archive access triggers\n"
"#			'%'bgtask'%    '      server-side user processes\n"
"#			'%'auth-check'%'      check authentication trigger\n"
"#			'%'auth-check-sso'%'  sso check authentication trigger\n"
"#			'%'auth-set'%'        set authentication trigger\n"
"#			'%'auth-invalidate'%' authentication invalidation trigger\n"
"#			'%'auth-pre-2fa'%'    mfa trigger - see '%'p4 help mfa'%'\n"
"#			'%'auth-init-2fa'%'   mfa trigger - see '%'p4 help mfa'%'\n"
"#			'%'auth-check-2fa'%'  mfa trigger - see '%'p4 help mfa'%'\n"
"#			'%'change-submit'%'   pre-submit triggers\n"
"#			'%'change-content'%'  modify content submit triggers\n"
"#			'%'change-commit'%'   post-submit triggers\n"
"#			'%'change-failed'%'   submit failure fires these triggers\n"
"#			'%'command'%'         pre/post user command triggers\n"
"#			'%'edge-submit'%'     Edge Server pre-submit\n"
"#			'%'edge-content'%'    Edge Server content submit\n"
"#			'%'failed-over'%'     post-failover trigger\n"
"#			'%'failed-back'%'     post-failback trigger\n"
"#			'%'fix-add'%'         pre-add fix triggers\n"
"#			'%'fix-delete'%'      pre-delete fix triggers\n"
"#			'%'form-in'%'         modify form in triggers\n"
"#			'%'form-out'%'        modify form out triggers\n"
"#			'%'form-save'%'       pre-save form triggers\n"
"#			'%'form-commit'%'     post-save form triggers\n"
"#			'%'form-delete'%'     pre-delete form triggers\n"
"#			'%'graph-push-start'%'      pre git push triggers\n"
"#			'%'graph-push-reference'%'  pre git reference update\n"
"#			'%'graph-push-reference-complete'%'\n"
"#			                        post git reference update\n"
"#			'%'graph-lfs-push'%'        pre lfs file triggers\n"
"#			'%'graph-push-complete'%'   post git push triggers\n"
"#			'%'heartbeat-missing'%'     heartbeat missing triggers\n"
"#			'%'heartbeat-resumed'%'     heartbeat resumed triggers\n"
"#			'%'heartbeat-dead'%'        heartbeat dead triggers\n"
"#			'%'journal-rotate'%'  post-journal rotation triggers\n"
"#			'%'journal-rotate-lock'%' blocking journal rotate triggers\n"
"#			'%'pull-archive'%'    archive transfer triggers\n"
"#			'%'push-submit'%'     pre-push triggers\n"
"#			'%'push-content'%'    modify content push triggers\n"
"#			'%'push-commit'%'     post-push triggers\n"
"#			'%'service-check'%'   check auth trigger (service users)\n"
"#			'%'shelve-submit'%'   pre-shelve triggers\n"
"#			'%'shelve-commit'%'   post-shelve triggers\n"
"#			'%'shelve-delete'%'   pre-delete shelve triggers\n"
"#\n"
"#  		%'Path'%:   For %'change-*'%, %'edge-*'%, or %'shelve-*'% triggers, a pattern\n"
"#			to match files in the changelist.\n"
"#\n"			
"#			For %'form-*'% triggers, the type of form: e.g. '%'branch'%'\n"
"#			'%'client'%', etc.\n"
"#\n"
"#			For %'fix-*'% triggers use '%'fix'%'.\n"
"#\n"
"#			For %'auth-*'% triggers use '%'auth'%'.\n"
"#\n"
"#			For %'graph-*'% triggers use a pattern to match repo names.\n"
"#\n"
"#			For archive triggers, a file pattern to match the\n"
"#			file name being accessed.\n"
"#\n"
"#			For command triggers, the client command to match.\n"
"#			Must be in the form \"%'(pre|post)-user-$command'%\",\n"
"#			e.g. \"%'pre-user-tag'%\".  The command name is a regular\n"
"#			expression.  See \"p4 help grep\" for details on\n"
"#			syntax.\n"
"#\n"
"#			For %'journal-rotate*'% triggers, use '%'any'%' or either the\n"
"#			%'server.id'% or %'cluster.id'% of the server(s) that\n"
"#			should run the triggers.\n"
"#\n"
"#			For %'failed-over'% triggers use '%'failed-over'%'.\n"
"#\n"
"#			For %'failed-back'% triggers use '%'failed-back'%'.\n"
"#\n"
"#			For %'heartbeat-*'% triggers use '%'heartbeat'%'.\n"
"#\n"
"#  		%'Command'%: The %'OS'% command to run for validation.  If the\n"
"#			 command contains spaces, the whole command must\n"
"#			 be quoted.  See '%'p4 help triggers'%' for a list of\n"
"#			 variables that can be expanded in the command\n"
"#			 string.\n"
"#\n"
"#  For example,\n"
"#\n"
"#	%'Triggers'%:\n"
"#		%'cscheck change-submit //depot/... \"cmd '%%%%'changelist'%%%%'\"'%\n"
"#		%'no-oblits command pre-user-obliterate fail'%\n"
"#		%'mkspec form-out client \"'%%%%'quote'%%%%'//trig/scr.pl'%%%%'quote'%%%%'\"'%\n"
"#		%'daily_verify bgtask unset \"verify.pl\"'%\n"
"#\n"
"# See '%'p4 help triggers'%' for more information about triggers.\n" };

ErrorId MsgSpec::SpecTypeMap = { ErrorOf( ES_SPEC, 9, E_INFO, EV_NONE, 0  ),
"# %'Perforce File Type'% Mapping Specifications.\n"
"#\n"
"#  %'TypeMap'%:	a list of filetype mappings; one per line.\n"
"#		Each line has two elements:\n"
"#\n"
"#  		%'Filetype'%: The filetype to use on '%'p4 add'%'.\n"
"#\n"
"#  		%'Path'%:     File pattern which will use this filetype.\n"
"#\n"
"# See '%'p4 help typemap'%' for more information.\n" };

ErrorId MsgSpec::SpecUser = { ErrorOf( ES_SPEC, 10, E_INFO, EV_NONE, 0  ),
"# A %'Perforce User'% Specification.\n"
"#\n"
"#  %'User'%:        The user's user name.\n"
"#  %'Type'%:        Either '%'service'%', '%'operator'%', or '%'standard'%'.\n"
"#               Default: '%'standard'%'. Read only.\n"
"#  %'Email'%:       The user's email address; for email review.\n"
"#  %'Update'%:      The date this specification was last modified.\n"
"#  %'Access'%:      The date this user was last active.  Read only.\n"
"#  %'FullName'%:    The user's real name.\n"
"#  %'JobView'%:     Selects jobs for inclusion during changelist creation.\n"
"#  %'Password'%:    If set, user must have matching %'$P4PASSWD'% on client.\n"
"#  %'AuthMethod'%:  '%'perforce'%' if using standard authentication or '%'ldap'%' if\n"
"#               this user should use native %'LDAP'% authentication.  The '+2fa'\n"
"#               modifier can be added to the AuthMethod, requiring the user to\n"
"#               perform multi factor authentication in addition to password\n"
"#               authentication. For example: '%'perforce+2fa'%'.\n"
"#  %'Reviews'%:     Listing of depot files to be reviewed by user.\n" };

ErrorId MsgSpec::SpecJob = { ErrorOf( ES_SPEC, 11, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Job'% Specification.\n"
"#\n"
"#  %'Job'%:         The job name.  '%'new'%' generates a sequenced job number.\n"
"#  %'Status'%:      Either '%'open'%', '%'closed'%', or '%'suspended'%'. Can be changed.\n"
"#  %'User'%:        The user who created the job. Can be changed.\n"
"#  %'Date'%:        The date this specification was last modified.\n"
"#  %'Description'%: Comments about the job.  Required.\n" };

ErrorId MsgSpec::SpecEditSpec = { ErrorOf( ES_SPEC, 12, E_INFO, EV_NONE, 0  ),
"# A %'Perforce Spec'% Specification.\n"
"#\n"
"#  Updating this form can be dangerous!\n"
"#  To update the job spec, see '%'p4 help jobspec'%' for proper directions.\n"
"#  To update the stream spec, see '%'p4 help streamspec'%' for proper directions.\n"
"#  Otherwise, see '%'p4 help spec'%'.\n" };

ErrorId MsgSpec::SpecRemote = { ErrorOf( ES_SPEC, 17, E_INFO, EV_NONE, 0  ), 
"# A %'Perforce Remote'% Specification.\n"
"#\n"
"#  %'RemoteID'%:    The remote identifier.\n"
"#  %'Address'%:     The %'P4PORT'% used by the remote server.\n"
"#  %'Owner'%:       The user who created this remote.\n"
"#  %'RemoteUser'%:  The user to use when connecting to the remote server.\n"
"#               May be overridden on fetch/push/login by --remote-user.\n"
"#  %'Options'%:     Remote options:\n"
"#                      %'[un]locked [no]compress [no]copyrcs'%\n"
"#  %'Update'%:      The date this specification was last modified.\n"
"#  %'Access'%:      The date of the last '%'push/fetch'%' on this remote.\n"
"#  %'Description'%: A short description of the remote server (optional).\n"
"#  %'LastFetch'%:   The last changelist that was fetched.\n"
"#  %'LastPush'%:    The last changelist that was pushed.\n"
"#  %'DepotMap'%:    Lines to map local files to remote files.\n"
"#  %'ArchiveLimits'%: Lines to limit the archives fetched (optional)\n"
"#\n"
"#                   See 'p4 help remote' for detailed information.\n" };

ErrorId MsgSpec::SpecRepo = { ErrorOf( ES_SPEC, 18, E_INFO, EV_NONE, 0  ), 
"# A %'Perforce Repo'% Specification.\n"
"#\n"
"#  %'Name'%:        The name of this repo.\n"
"#  %'Owner'%:       The user who created this repo.\n"
"#  %'Created'%:     The date this specification was created.\n"
"#  %'Pushed'%:      The date of the last '%'push'%' to this repo.\n"
"#  %'Options'%:     Repo options:\n"
"#                       %'[no]lfs'%\n"
"#  %'Description'%: A short description of the repo (optional).\n"
"#  %'MirroredFrom'%:  Upstream URL this read-only repo is mirrored from.\n"
"#  %'GconnMirrorServerId'%:  Server-Id of the git-connector that handles mirroring.\n"
"#  %'GconnMirrorSecretToken'%:  The webhook SecretToken that the \n"
"#                       \"gconn --mirrorhooks add\" command generates.\n"
"#  %'GconnMirrorStatus'%:  Status of repo mirroring through the git-connector.\n"
"#  %'GconnMirrorExcludedBranches'%:  Branch names to be excluded in mirroring.\n"
"#  %'GconnMirrorHideFetchUrl'%:  If true, hide the upstream url in msg to git user.\n"
"#  %'DefaultBranch'%: The default branch to clone (eg, \"refs/heads/trunk\" or\n"
"#                 \"trunk\"); it must begin with \"refs/\" if git is to use it.\n"
"#\n"
"#                   See 'p4 help repo' for detailed information.\n" };

ErrorId MsgSpec::SpecExtension = { ErrorOf( ES_SPEC, 19, E_INFO, EV_NONE, 0  ), 
"# A %'Perforce Extension'% Specification.\n"
"#\n"
"#  %'ExtName'%:          The name of the Extension being configured.\n"
"#  %'ExtDescription'%:   The description of the Extension being configured.\n"
"#  %'ExtVersion'%:       The version of the Extension being configured.\n"
"#  %'ExtUUID'%:          The UUID/key of the Extension being configured.\n"
"#  %'ExtRev'%:           The revision of the Extension being configured.\n"
"#  %'ExtMaxScriptTime'%: Maximum seconds the Extension may be run.\n"
"#  %'ExtMaxScriptMem'%:  Maximum megabytes the Extension may use.\n"
"#  %'ExtAllowedGroups'%: Groups whose members may configure the Extension.\n"
"#  %'ExtEnabled'%:       Enable/Disable this Extension.\n"
"#  %'ExtP4USER'%:        Perforce user account for the Extension to use.\n"
"#  %'Name'%:             The name of this Extension config.\n"
"#  %'Owner'%:            The user who created this Extension config.\n"
"#  %'Update'%:           Update time for the Extension config spec.\n"
"#  %'Description'%:      The description of this Extension config.\n"
"#  %'ExtConfig'%:        Extension-supplied configuration fields.\n"
"#\n"
"# See 'p4 help extension' for detailed information.\n" };

ErrorId MsgSpec::SpecExtensionIns = { ErrorOf( ES_SPEC, 20, E_INFO, EV_NONE, 0  ), 
"# A %'Perforce Extension'% Specification.\n"
"#\n"
"#  %'ExtName'%:          The name of the Extension being configured.\n"
"#  %'ExtDescription'%:   The description of the Extension being configured.\n"
"#  %'ExtVersion'%:       The version of the Extension being configured.\n"
"#  %'ExtUUID'%:          The UUID/key of the Extension being configured.\n"
"#  %'ExtRev'%:           The revision of the Extension being configured.\n"
"#  %'ExtMaxScriptTime'%: Maximum seconds the Extension may be run.\n"
"#  %'ExtMaxScriptMem'%:  Maximum megabytes the Extension may use.\n"
"#  %'ExtEnabled'%:       Enable/Disable this Extension.\n"
"#  %'ExtDebug'%:         Enable Extension diagnostics.\n"
"#  %'Name'%:             The name of this Extension config.\n"
"#  %'Owner'%:            The user who created this Extension config.\n"
"#  %'Update'%:           Update time for the Extension config spec.\n"
"#  %'Description'%:      The description of this Extension config.\n"
"#  %'ExtConfig'%:        Extension-supplied configuration fields.\n"
"#\n"
"# See 'p4 help extension' for detailed information.\n" };

ErrorId MsgSpec::SpecHotFiles = { ErrorOf( ES_SPEC, 21, E_INFO, EV_NONE, 0  ),
"# %'Perforce File Type'% Mapping Specifications.\n"
"#\n"
"#  %'Hotfiles'%:	a list of hotfiles mappings; one per line.\n"
"#		Each line has a %'Path'% and two optional elements.\n"
"#		Duplicate %'Path'% elements are supported:\n"
"#\n"
"#  		%'Path'%:     File pattern which will be mapped to hotfiles.\n"
"#\n"
"#  		%'Filetype'%: See 'p4 help filetypes' for a list of valid\n"
"#  		          filetypes.\n"
"#\n"
"#  		%'Size'%:     '<' or '>' followed by numeric value in bytes,\n"
"#  		          followed by an optional unit specifier K/M/G/T.\n"
"#\n"
"# See '%'p4 help hotfiles'%' for more information.\n" };

// ErrorId graveyard: retired/deprecated ErrorIds. 
