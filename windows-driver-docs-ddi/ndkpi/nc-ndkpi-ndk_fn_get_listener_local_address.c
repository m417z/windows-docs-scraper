NDK_FN_GET_LISTENER_LOCAL_ADDRESS NdkFnGetListenerLocalAddress;

NTSTATUS NdkFnGetListenerLocalAddress(
  [in] NDK_LISTENER *pNdkListener,
       PSOCKADDR pAddress,
       ULONG *pAddressLength
)
{...}