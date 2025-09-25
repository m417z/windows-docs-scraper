typedef struct _SAFER_CODE_PROPERTIES_V2 {
  DWORD         cbSize;
  DWORD         dwCheckFlags;
  LPCWSTR       ImagePath;
  HANDLE        hImageFileHandle;
  DWORD         UrlZoneId;
  BYTE          ImageHash[SAFER_MAX_HASH_SIZE];
  DWORD         dwImageHashSize;
  LARGE_INTEGER ImageSize;
  ALG_ID        HashAlgorithm;
  LPBYTE        pByteBlock;
  HWND          hWndParent;
  DWORD         dwWVTUIChoice;
  LPCWSTR       PackageMoniker;
  LPCWSTR       PackagePublisher;
  LPCWSTR       PackageName;
  ULONG64       PackageVersion;
  BOOL          PackageIsFramework;
} SAFER_CODE_PROPERTIES_V2, *PSAFER_CODE_PROPERTIES_V2;