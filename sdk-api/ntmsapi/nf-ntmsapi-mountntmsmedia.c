DWORD MountNtmsMedia(
  [in]      HANDLE                   hSession,
  [in]      LPNTMS_GUID              lpMediaId,
  [in, out] LPNTMS_GUID              lpDriveId,
  [in]      DWORD                    dwCount,
  [in]      DWORD                    dwOptions,
  [in]      int                      dwPriority,
  [in]      DWORD                    dwTimeout,
            LPNTMS_MOUNT_INFORMATION lpMountInformation
);