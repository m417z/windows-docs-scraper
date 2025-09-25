NDK_FN_GET_PEER_ADDRESS NdkFnGetPeerAddress;

NTSTATUS NdkFnGetPeerAddress(
  [in] NDK_CONNECTOR *pNdkConnector,
       PSOCKADDR pAddress,
       ULONG *pAddressLength
)
{...}