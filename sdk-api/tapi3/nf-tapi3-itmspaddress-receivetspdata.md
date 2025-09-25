# ITMSPAddress::ReceiveTSPData

## Description

The
**ReceiveTSPData** method is called by TAPI 3 when the TSP sends asynchronous data to the MSP. If the TSP sends the
[LINE_SENDMSPDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-sendmspdata) message with the **htCall** set to **NULL**, *pMSPCall* will be **NULL**. If the TSP does specify the **htCall**, *pMSPCall* will correspond to the call created in
[CreateMSPCall](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-createmspcall).

## Parameters

### `pMSPCall` [in]

Pointer to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the MSP Call object.

### `pBuffer`

[in, size_is(*dwSize*)] Pointer to opaque buffer from the TSP.

### `dwSize` [in]

Size, in bytes, of *pBuffer*.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pMSPCall* or *pBuffer* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *pMSPCall* parameter is **NULL**. |
| **E_FAIL** | The *pMSPCall* parameter does not point to a valid interface. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The MSP must free memory in *pBuffer*.

The semantics of the data passed in the buffer are specific to each TSP/MSP pair. This method simply dispatches the received buffer to the address (*pMSPCall* == **NULL**) or the indicated call (*pMSPCall* != **NULL**).

## See also

[ITMSPAddress](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itmspaddress)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)