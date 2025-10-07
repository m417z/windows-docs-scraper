typedef struct _OP_JOINPROV4_PART
{
    DWORD Rid;
    [string] wchar_t *lpSid;
    GUID ObjectGuid;
} OP_JOINPROV4_PART, *POP_JOINPROV4_PART;