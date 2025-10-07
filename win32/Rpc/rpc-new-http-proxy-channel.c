typedef RPC_STATUS
(__RPC_USER * RPC_NEW_HTTP_PROXY_CHANNEL) (
    _In_ RPC_HTTP_REDIRECTOR_STAGE RedirectorStage,
    _In_ RPC_WSTR ServerName, _In_ RPC_WSTR ServerPort,
    _In_opt_ RPC_WSTR RemoteUser,
    _In_opt_ RPC_WSTR AuthType,
    _Inout_ void __RPC_FAR * ResourceUuid,
    _Inout_ void __RPC_FAR * SessionId,
    _In_opt_ void __RPC_FAR * Interface,
    _In_opt_ void __RPC_FAR * Reserved,
    _In_ unsigned long Flags,
    _Outptr_opt_ RPC_WSTR __RPC_FAR * NewServerName,
    _Outptr_opt_ RPC_WSTR __RPC_FAR * NewServerPort
);