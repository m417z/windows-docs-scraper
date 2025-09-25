typedef struct _DXGK_ALLOCATIONLIST
{
    HANDLE              hDeviceSpecificAllocation;
    struct
    {
        UINT            WriteOperation  : 1;    // 0x00000001
        UINT            SegmentId       : 5;    // 0x0000002E
        UINT            Reserved        : 26;   // 0xFFFFFFC0
    };
#if (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_0)
    union
    {
        PHYSICAL_ADDRESS        PhysicalAddress;
        D3DGPU_VIRTUAL_ADDRESS  VirtualAddress;
    };
#else // (DXGKDDI_INTERFACE_VERSION < DXGKDDI_INTERFACE_VERSION_WDDM2_0)
    PHYSICAL_ADDRESS    PhysicalAddress;
#endif // (DXGKDDI_INTERFACE_VERSION >= DXGKDDI_INTERFACE_VERSION_WDDM2_0)
} DXGK_ALLOCATIONLIST;