struct FW_RULE
{
	FW_RULE* pNext;
	WORD wSchemaVersion;

	LPWSTR wszRuleId;
	LPWSTR wszName;
	LPWSTR wszDescription;

	DWORD dwProfiles;

	FW_DIRECTION Direction;
	WORD wIpProtocol;
	union
	{
		struct
		{
			FW_PORTS LocalPorts;
			FW_PORTS RemotePorts;
		};

		FW_ICMP_TYPE_CODE_LIST V4TypeCodeList;
		FW_ICMP_TYPE_CODE_LIST V6TypeCodeList;
	};

	FW_ADDRESSES LocalAddresses;
	FW_ADDRESSES RemoteAddresses;
	FW_INTERFACE_LUIDS LocalInterfaceIds;
	DWORD dwLocalInterfaceTypes;
	LPWSTR wszLocalApplication;
	LPWSTR wszLocalService;

	FW_RULE_ACTION Action;
	WORD wFlags;

	LPWSTR wszRemoteMachineAuthorizationList;
	LPWSTR wszRemoteUserAuthorizationList;

	LPWSTR wszEmbeddedContext;
	FW_OS_PLATFORM_LIST PlatformValidityList;

	FW_RULE_STATUS Status;
	FW_RULE_ORIGIN_TYPE Origin;
	LPWSTR wszGPOName;
	DWORD Reserved;

	FW_OBJECT_METADATA* pMetaData;

	WCHAR* wszLocalUserAuthorizationList;

	WCHAR* wszPackageId;

	WCHAR* wszLocalUserOwner;

	DWORD dwTrustTupleKeywords;

	FW_NETWORK_NAMES OnNetworkNames;

    WCHAR* wszSecurityRealmId;

	WORD wFlags2;

	FW_NETWORK_NAMES RemoteOutServerNames;

	WCHAR* wszFqbn;

	DWORD compartmentId;
};