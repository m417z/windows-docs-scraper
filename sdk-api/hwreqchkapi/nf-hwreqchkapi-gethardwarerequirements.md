## Description

This API returns a collection of defined hardware requirements for all product-types.

## Parameters

### `deviceHardwareRequirements`

Returns the list of all defined hardware requirements. Any of the hardware requirements returned can be used to evaluate the hardware requirements.

>[!NOTE]
>Internally, the API allocates memory for this argument using **CoTaskMemAlloc** and it is the responsibility of the caller to free the memory using **CoTaskMemFree**.

### `requirementCount`

The number of **HWREQCHK_DEVICE_HARDWARE_REQUIREMENT** items that are returned in *deviceHardwareRequirements*.

## Return value

Returns an `HRESULT` value that indicates the success or failure of the call.

## Remarks

## See also