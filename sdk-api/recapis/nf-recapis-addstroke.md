# AddStroke function

## Description

Adds an ink stroke to the [RecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class).

## Parameters

### `hrc`

The handle to the recognizer context.

### `pPacketDesc`

Describes the contents of the packets. The description must match the contents of the packets in *pPacket*. If **NULL**, this function uses the [GetPreferredPacketDescription](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getpreferredpacketdescription) function.

### `cbPacket`

Size, in bytes, of the *pPacket* buffer.

### `pPacket`

Array of packets that contain tablet space coordinates.

### `pXForm`

Describes the transform that can be applied to ink to transform it from tablet space into ink space. A recognizer may choose to ignore this transform and implement their own ink rotation algorithms. These recognizers should still return properties calculated in the lattice data relative to this transform.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **TPC_E_INVALID_PACKET_DESCRIPTION** | The packet description does not contain the necessary information for the packet to be considered valid. For example, it does not include a GUID_X or GUID_Y property. |
| **TPC_E_OUT_OF_ORDER_CALL** | The call to the method was made out of order. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |

## Remarks

The recognizer must return properties such as [Baseline](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognitionalternate-get_baseline) in ink space coordinates rather than tablet coordinates.

It is recommended that your recognizer place a limit on the number of strokes per context and/or the points allowed in a given stroke. Limit input to 1024 strokes per context and 32767 points per stroke.

Strokes with zero points are not allowed. You should return E_FAIL in such a case.

## See also

[GetPreferredPacketDescription](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getpreferredpacketdescription)

[PACKET_DESCRIPTION Structure](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_description)