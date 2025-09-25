# ITAddress::CreateCall

## Description

The
**CreateCall** method creates a new Call object that can be used to make an outgoing call and returns a pointer to the object's
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) interface. The newly created call is in the CS_IDLE
[state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) and has no media or terminals selected.

Acceptable input values for call address, address type, and media types are specific to the telephony service provider that supports the current address. For information on TSPs shipped with Windows 2000, see
[About The Telephony Service Provider (TSP)](https://learn.microsoft.com/windows/desktop/Tapi/about-the-telephony-service-provider-tsp-). For third party TSPs, see the documentation provided by the vender.

## Parameters

### `pDestAddress` [in]

This **BSTR** string contains a destination address. The format is provider-specific. This pointer can be **NULL** for non-dialed addresses (such as with a hot phone) or when all dialing is performed using
[ITBasicCallControl::Dial](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-dial). **NULL** in combination with a **NULL***pGroupID* in
[ITBasicCallControl::Pickup](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-pickup) results in a group pickup. Service providers that have inverse multiplexing capabilities can allow an application to specify multiple addresses at once.

### `lAddressType` [in]

Contains an
[address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) constant, such as LINEADDRESSTYPE_PHONENUMBER, which describes the format of the address. The value must be valid for this address. Use
[ITAddressCapabilities::get_AddressCapability](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddresscapabilities-get_addresscapability) with *AddressCap* set to AC_ADDRESSTYPES to verify the value.

### `lMediaTypes` [in]

Identifies the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types that will be involved in the call session.

### `ppCall` [out]

Pointer to
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The address type, *lAddressType*, is invalid or specifies more than one address type. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppCall* parameter is not a valid pointer. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDestAddress* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

When the address type is LINEADDRESSTYPE_SDP, the application should call the
[ITSDP::get_IsValid](https://learn.microsoft.com/windows/desktop/Tapi/itsdp-get-isvalid) method on *pDestAddress* to verify that the SDP information contained is properly constructed according to RFC 2327.

Calls used as consultation calls, such as during a conference, transfer, or forward operation, must be created using this method.

TAPI calls the **AddRef** method on the
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) interface returned by **ITAddress::CreateCall**. The application must call **Release** on the
**ITBasicCallControl** interface to free resources associated with it.

**Note** This method is not precisely the same as
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) in TAPI 2. It supplies TAPI with much of the same information, but parallel operations are not performed until
[ITBasicCallControl::Connect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-connect) is called.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[ITBasicCallControl::Dial](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-dial)

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)