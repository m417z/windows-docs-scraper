# ID2D1Factory1::GetRegisteredEffects

## Description

Returns the class IDs of the currently registered effects and global effects on this factory.

## Parameters

### `effects` [out]

Type: **[CLSID](https://learn.microsoft.com/windows/desktop/com/clsid)***

When this method returns, contains an array of effects. **NULL** if no effects are retrieved.

### `effectsCount`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint32_description)**

The capacity of the *effects* array.

### `effectsReturned` [out]

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint32_description)***

When this method returns, contains the number of effects copied into *effects*.

### `effectsRegistered` [out, optional]

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint32_description)***

When this method returns, contains the number of effects currently registered in the system.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) | *effectsRegistered* is larger than *effectCount*. |

## Remarks

The set of class IDs will be atomically returned by the API. The set will not be interrupted by other threads registering or unregistering effects.

If *effectsRegistered* is larger than *effectCount*, the supplied array will still be filled to capacity with the current set of registered effects. This method returns the CLSIDs for all global effects and all effects registered to this factory.

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)

[ID2D1Factory1::RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring)