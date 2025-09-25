# IPrintCoreHelperUni::CreateDefaultGDLSnapshot

## Description

The `IPrintCoreHelperUni::CreateDefaultGDLSnapshot` method gets a GDL snapshot based on the driver default configuration.

## Parameters

### `dwFlags` [in]

This parameter is reserved and must be set to zero.

### `ppSnapshotStream` [out]

A pointer to a stream that supplies the XML version of the GDL snapshot.

## Return value

`IPrintCoreHelperUni::CreateDefaultGDLSnapshot` should return S_OK if the operation succeeds. Otherwise, this method should return a standard COM error code.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::CreateGDLSnapshot](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-creategdlsnapshot)