# IBDA_NameValueService::SetValue

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sets a name/value pair in device memory.

## Parameters

### `ulDialogRequest` [in]

Specifies a logical link with a user interface (MMI) dialog box that might be triggered by setting the value.

### `bstrLanguage` [in]

The language of the dialog box. This string contains an ISO 639-2 language code with a dash followed by an ISO 3166 country/region code.

### `bstrName` [in]

The name of the name/value pair to set.

### `bstrValue` [in]

The value to set.

### `ulReserved` [in]

Reserved. Set to zero.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_NameValueService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_namevalueservice)