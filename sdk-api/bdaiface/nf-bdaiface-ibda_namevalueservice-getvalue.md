# IBDA_NameValueService::GetValue

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a value by name.

## Parameters

### `bstrName` [in]

The name of the value to retrieve.

### `bstrLanguage` [in]

The language for the value. If the value of the name/value pair is localizable, this string must contain an ISO 639-2 language code with a dash followed by an ISO 3166 country/region code. Otherwise, this parameter may contain an empty string.

### `pbstrValue` [out]

Receives the value as a **BSTR**. The caller must free the **BSTR** by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_NameValueService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_namevalueservice)