# IPhotoAcquireOptionsDialog::Initialize

## Description

Initializes the options dialog box and reads any saved options from the registry.

## Parameters

### `pszRegistryRoot` [in]

(optional) Pointer to a null-terminated string containing the registry root of a custom location to read the acquisition settings from. If this parameter is set to **NULL**, the default location will be used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

`Initialize` must be called prior to calling [Create](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireoptionsdialog-create) or [DoModal](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireoptionsdialog-domodal). Failure to do so will cause **Create** or **DoModal** to fail.

If `Initialize` is called while the options dialog box is already displayed, an error will be returned.

## See also

[IPhotoAcquireOptionsDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireoptionsdialog)