# IBDA_ISDBConditionalAccess::SetIsdbCasRequest

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Sends a conditional access system (CAS) command for Integrated Services Digital Broadcasting (ISDB).

## Parameters

### `ulRequestId` [in]

The numeric code for the CAS command. The ARIB standard defines these values. Enumeration constants for some commands are defined in the [ISDBCAS_REQUEST_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/isdbcas-request-id) enumeration.

### `ulcbRequestBufferLen` [in]

Size of the *pbRequestBuffer* array, in bytes.

### `pbRequestBuffer` [in]

Pointer to a byte array that contains the data for the command.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_ISDBConditionalAccess](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_isdbconditionalaccess)