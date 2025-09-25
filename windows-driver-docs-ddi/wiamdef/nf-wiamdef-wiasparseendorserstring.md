# wiasParseEndorserString function

## Description

The **wiasParseEndorserString** function parses an endorser string, replacing WIA service-defined and vendor-defined tokens in the string with values associated with those tokens.

## Parameters

### `pWiasContext` [in]

Pointer to a WIA Item context (the context of the item containing the WIA_DPS_ENDORSER_STRING property (described in the Microsoft Windows SDK documentation)).

### `lFlags`

Reserved for system use and should be set to 0.

### `pInfo` [out, optional]

Pointer to a [WIAS_ENDORSER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_info) structure containing the page count and a list of custom token/value pairs. Can be **NULL**.

### `pOutputString` [out]

Pointer to a memory location that receives the address of the parsed endorser string. If **pOutputString* is non-NULL on entry, then the function assumes that the caller allocated the buffer; otherwise the WIA service will allocate it. Note that the WIA service assumes the *maximum* resultant endorser string is MAX_PATH (defined in *stdlib.h*) characters long. If the driver expects the string to be longer, it should allocate the buffer itself. If the caller allocates the buffer, it *must* initialize the contents of the buffer to zero before using this function.

## Return value

On success, the function returns S_OK.

If the function fails, it returns a standard COM error or one of the [WIA error codes](https://learn.microsoft.com/windows/win32/wia/-wia-error-codes).

## Remarks

An application sets the WIA_DPS_ENDORSER_STRING property to a string that can contain the WIA service-defined tokens $DATE$, $TIME$, $PAGE_COUNT$, $DAY$, $MONTH$, and $YEAR$, as well as vendor-defined tokens. After a driver calls **wiasParseEndorserString**, the string pointed to by *pOutputString* contains a copy of the string in WIA_DPS_ENDORSER_STRING property, but with any tokens replaced by the values the tokens represent. For example, if the application set the endorser string to "This page was scanned on $DATE$", and the current date was October 1, 2000, the resulting output string would be "This page was scanned on 2000/10/1".

The list of standard WIA endorser tokens can be found in *wiadef.h*.

Drivers can request that **wiasParseEndorserString** substitute values for vendor-defined tokens by filling out a [WIAS_ENDORSER_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_value) structure for each token/value pair, and packaging all of these structures in a [WIAS_ENDORSER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_info) structure. The following example shows how this function can be used.

```cpp
HRESULT hr  = S_OK;
BSTR  bstrResultingEndorser   = NULL;
WIAS_ENDORSER_VALUE  aMyTokens[] = {L"$MY_TOKEN$", L"My value"};
WIAS_ENDORSER_INFO  Info     = {0, 1, aMyTokens};
hr = wiasParseEndorserString(pWiasContext, 0,
                             &Info, &bstrResultingEndorser);
```

Assuming that the WIA_DPS_ENDORSER_STRING property contains "This is $MY_TOKEN$", and that the call to **wiasParseEndorserString** was successful, *bstrResultingEndorser* will now contain "This is My value".

## See also

[WIAS_ENDORSER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_info)

[WIAS_ENDORSER_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_value)