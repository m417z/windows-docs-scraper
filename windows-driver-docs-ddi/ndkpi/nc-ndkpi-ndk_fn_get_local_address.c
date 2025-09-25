NDK_FN_GET_LOCAL_ADDRESS NdkFnGetLocalAddress;

NTSTATUS NdkFnGetLocalAddress(
  [in] NDK_CONNECTOR *pNdkConnector,
       PSOCKADDR pAddress,
       ULONG *pAddressLength
)
{...}