NDK_FN_GET_SHARED_ENDPOINT_LOCAL_ADDRESS NdkFnGetSharedEndpointLocalAddress;

NTSTATUS NdkFnGetSharedEndpointLocalAddress(
  [in] NDK_SHARED_ENDPOINT *pNdkSharedEndpoint,
       PSOCKADDR pAddress,
       ULONG *pAddressLength
)
{...}