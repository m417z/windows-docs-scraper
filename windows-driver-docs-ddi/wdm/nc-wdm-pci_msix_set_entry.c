PCI_MSIX_SET_ENTRY PciMsixSetEntry;

NTSTATUS PciMsixSetEntry(
  [in] PVOID Context,
  [in] ULONG TableEntry,
  [in] ULONG MessageNumber
)
{...}