HRESULT
EdpAuditAction(
    _In_ PCWSTR ObjectDescription,
    _In_ EDP_AUDIT_ACTION Action,
    _In_opt_ PCWSTR SourceName,
    _In_opt_ PCWSTR SourceEID,
    _In_opt_ PCWSTR DestinationName,
    _In_opt_ PCWSTR DestinationEID,
    _In_opt_ PCWSTR Application
    );