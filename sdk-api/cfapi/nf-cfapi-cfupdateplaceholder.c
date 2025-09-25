HRESULT CfUpdatePlaceholder(
  [in]                HANDLE               FileHandle,
  [in, optional]      const CF_FS_METADATA *FsMetadata,
  [in, optional]      LPCVOID              FileIdentity,
  [in]                DWORD                FileIdentityLength,
  [in, optional]      const CF_FILE_RANGE  *DehydrateRangeArray,
  [in]                DWORD                DehydrateRangeCount,
  [in]                CF_UPDATE_FLAGS      UpdateFlags,
  [in, out, optional] USN                  *UpdateUsn,
  [in, out, optional] LPOVERLAPPED         Overlapped
);