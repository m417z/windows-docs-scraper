typedef struct _DXGK_DEBUG_REPORT_INTERFACE {
  USHORT                    Size;
  USHORT                    Version;
  PVOID                     Context;
  PINTERFACE_REFERENCE      InterfaceReference;
  PINTERFACE_DEREFERENCE    InterfaceDereference;
  DXGK_DEBUG_REPORT_HANDLE( )(HANDLE DeviceHandle,ULONG ulCode,ULONG_PTR ulpArg1,ULONG_PTR ulpArg2,ULONG_PTR ulpArg3,ULONG_PTR ulpArg4) *DbgReportCreate;
  BOOLEAN( )(DXGK_DEBUG_REPORT_HANDLE hReport,PVOID pvData,ULONG ulDataSize)                  *DbgReportSecondaryData;
  VOID( )(DXGK_DEBUG_REPORT_HANDLE hReport)                     *DbgReportComplete;
} DXGK_DEBUG_REPORT_INTERFACE, *PDXGK_DEBUG_REPORT_INTERFACE;