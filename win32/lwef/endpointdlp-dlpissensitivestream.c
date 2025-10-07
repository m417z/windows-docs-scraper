#define DLP_ISS_FLAG_TEXT                   0x00000001
#define DLP_ISS_FLAG_SUPPRESS_DEFENDER_UX   0x00000400
HRESULT WINAPI DlpIsSensitiveStream(_In_ DWORD cbBuffer, _In_reads_bytes_(cbBuffer) LPCVOID pvBuffer, _In_ LPCWSTR url, _In_ DWORD flags, _In_ PVOID pReserved, _Out_ DlpEnforcementLevel *enforcementLevel, _Out_ DlpTraceInfoEx* traceInfoEx);