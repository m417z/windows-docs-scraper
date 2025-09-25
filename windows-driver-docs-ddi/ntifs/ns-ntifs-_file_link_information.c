typedef struct _FILE_LINK_INFORMATION {
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5)
    union {
        BOOLEAN ReplaceIfExists;  // FileLinkInformation
        ULONG Flags;              // FileLinkInformationEx
    } DUMMYUNIONNAME;
#else
    BOOLEAN ReplaceIfExists;
#endif
    HANDLE RootDirectory;
    ULONG FileNameLength;
    WCHAR FileName[1];
} FILE_LINK_INFORMATION, *PFILE_LINK_INFORMATION;