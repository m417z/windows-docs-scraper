CLFSUSER_API BOOL PrepareLogArchive(
  [in]            HANDLE                    hLog,
  [in, out]       PWSTR                     pszBaseLogFileName,
  [in]            ULONG                     cLen,
  [in, optional]  const PCLFS_LSN           plsnLow,
  [in, optional]  const PCLFS_LSN           plsnHigh,
  [out, optional] PULONG                    pcActualLength,
  [out]           PULONGLONG                poffBaseLogFileData,
  [out]           PULONGLONG                pcbBaseLogFileLength,
  [out]           PCLFS_LSN                 plsnBase,
  [out]           PCLFS_LSN                 plsnLast,
  [out]           PCLFS_LSN                 plsnCurrentArchiveTail,
  [out]           PCLFS_LOG_ARCHIVE_CONTEXT ppvArchiveContext
);