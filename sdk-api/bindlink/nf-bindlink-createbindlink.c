HRESULT CreateBindLink(
  PCWSTR                 virtualPath,
  PCWSTR                 backingPath,
  CREATE_BIND_LINK_FLAGS createBindLinkFlags,
  UINT32                 exceptionCount,
  PCWSTR * const         exceptionPaths
);