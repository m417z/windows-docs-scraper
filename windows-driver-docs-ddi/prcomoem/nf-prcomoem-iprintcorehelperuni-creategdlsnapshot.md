# IPrintCoreHelperUni::CreateGDLSnapshot

## Description

The `IPrintCoreHelperUni::CreateGDLSnapshot` method creates a GDL snapshot of the driver configuration file based on the current configuration.

## Parameters

### `pDevmode` [in]

A pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure. If this pointer is provided, `IPrintCoreHelperUni::CreateGDLSnapshot` should use the DEVMODEW structure that is pointed to by *pDevmode* instead of the default or current DEVMODEW structure. If this method is called from the plug-in provider, there is no default DEVMODEW structure and the *pDevmode* parameter is required.

### `cbSize` [in]

The size, in bytes, of the DEVMODEW structure that is pointed to by the *pDevmode* parameter.

### `dwFlags` [in]

Reserved for system use. This parameter must be set to zero.

### `ppSnapshotStream` [out]

A pointer to a stream that supplies the XML version of the GDL snapshot.

## Return value

`IPrintCoreHelperUni::CreateGDLSnapshot` should return S_OK if the operation succeeds. Otherwise, this method should return a standard COM error code.

## See also

[IPrintCoreHelperUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcorehelperuni)

[IPrintCoreHelperUni::CreateDefaultGDLSnapshot](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintcorehelperuni-createdefaultgdlsnapshot)