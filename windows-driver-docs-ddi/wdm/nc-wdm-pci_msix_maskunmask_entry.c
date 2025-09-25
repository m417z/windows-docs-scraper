PCI_MSIX_MASKUNMASK_ENTRY PciMsixMaskunmaskEntry;

NTSTATUS PciMsixMaskunmaskEntry(
  [in] PVOID Context,
  [in] ULONG TableEntry
)
{...}