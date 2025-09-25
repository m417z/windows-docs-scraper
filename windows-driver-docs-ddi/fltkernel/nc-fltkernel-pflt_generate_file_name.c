PFLT_GENERATE_FILE_NAME PfltGenerateFileName;

NTSTATUS PfltGenerateFileName(
  [in]           PFLT_INSTANCE Instance,
  [in]           PFILE_OBJECT FileObject,
  [in, optional] PFLT_CALLBACK_DATA CallbackData,
  [in]           FLT_FILE_NAME_OPTIONS NameOptions,
  [out]          PBOOLEAN CacheFileNameInformation,
  [out]          PFLT_NAME_CONTROL FileName
)
{...}