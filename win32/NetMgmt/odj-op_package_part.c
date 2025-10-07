typedef struct _OP_PACKAGE_PART
{
    GUID    PartType;
    ULONG   ulFlags;
    OP_BLOB Part;
    OP_BLOB Extension;
} OP_PACKAGE_PART, *POP_PACKAGE_PART;