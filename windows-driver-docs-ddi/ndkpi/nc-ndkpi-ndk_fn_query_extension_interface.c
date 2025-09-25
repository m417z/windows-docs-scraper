NDK_FN_QUERY_EXTENSION_INTERFACE NdkFnQueryExtensionInterface;

NTSTATUS NdkFnQueryExtensionInterface(
  [in]  NDK_OBJECT_HEADER *pNdkObject,
  [in]  GUID *ExtensionInterfaceID,
  [in]  NDK_VERSION ExtensionInterfaceVersion,
  [out] NDK_EXTENSION_INTERFACE *pExtensionInterface
)
{...}