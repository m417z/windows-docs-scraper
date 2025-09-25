# IBDA_ConditionalAccessEx::CheckEntitlementToken

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Checks the access availability of content that is identified by an entitlement token.

An *entitlement token* is a binary blob used to obtain access to a piece of content or to identify an event in a stream.

## Parameters

### `ulDialogRequest` [in]

A dialog request number that specifies the dialog that might be triggered by setting the value. A dialog is part of the device's user interface (MMI).

### `bstrLanguage` [in]

The language of the dialog. This string contains an ISO 639-2 language code with a dash followed by an ISO 3166 country/region code.

### `RequestType` [in]

The type of access that is being requested, specified as a member of the [BDA_CONDITIONALACCESS_REQUESTTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-conditionalaccess-requesttype) enumeration.

### `ulcbEntitlementTokenLen` [in]

The size, in bytes, of the *pbEntitlementToken* array.

### `pbEntitlementToken` [in]

Pointer to a byte array that contains the entitlement token.

### `pulDescrambleStatus` [out]

Receives a status code indicating the descrambling status. For more information, see *Protected Broadcast Driver Architecture, Part 1: Core Services*, section 5.5.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_ConditionalAccessEx](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccessex)