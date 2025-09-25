# PFND3DDDI_CHECKCOUNTER callback function

## Description

**PFND3DDDI_CHECKCOUNTER** is called by the Direct3D runtime to retrieve info that describes a counter. Must be implemented by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Parameters

### `hDevice`

[in] A handle to the display device (graphics context).

### `unnamedParam2`

[in] **Counter** is a value of type [**D3DDDIQUERYTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) that identifies the counter identifier that info is retrieved for.

### `unnamedParam3`

[out] **pType** is a pointer to a variable that receives a [**D3DDDI_COUNTER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_counter_type) enumeration value that identifies the data type that the counter outputs.

### `unnamedParam4`

*pActiveCounters* [out] **pActiveCounters** is a pointer to a variable that receives the number of simultaneously active counters that are allocated for the creation of the counter identifier that the **Counter** parameter identifies.

### `unnamedParam5`

[out, optional] **pszName** is an optional pointer that the driver returns a NULL-terminated string to that contains the name of the counter identifier.

Can be NULL, in which case the app doesn't need the name.

### `pNameLength`

[in, out, optional] An optional pointer to a variable that receives the size, in bytes, of the NULL-terminated string that the **pszName** parameter specifies.

Here are limitations on the values of the **pNameLength** and **pszName** parameters:

* **pNameLength** can be NULL, in which case the app doesn't need the name or name length.
* If **pszName** is NULL and **pNameLength** is not NULL, the input value of **pNameLength** is ignored, and the length of the string (including terminating NULL character) must be returned through the **pNameLength** parameter.
* If both **pszName** and **pNameLength** are not NULL, the driver must check the input value of **pNameLength** to ensure that there's enough room in the allocated buffer, and then the length of the **pszName** string (including terminating NULL character) is passed out through the **pNameLength** parameter.

### `unnamedParam7`

[out, optional] **pszUnits** is an optional pointer that the driver returns a NULL-terminated string to that contains the name of the units that the counter identifier measures.

Can be NULL, in which case the app doesn't need the units info. See more info in the explanation of the **pUnitsLength** parameter.

### `pUnitsLength`

[in, out, optional] **pUnitsLength** is an optional pointer to a variable that receives the size, in bytes, of the NULL-terminated string that the **pszUnits** parameter specifies.

Here are limitations on the values of the **pUnitsLength** and **pszUnits** parameters:

* **pUnitsLength** can be NULL, in which case the app doesn't need the unit name or unit name length.
* If **pszUnits** is NULL and **pUnitsLength** is not NULL, the input value of **pUnitsLength** is ignored, and the length of the string (including terminating NULL character) must be returned through the **pUnitsLength** parameter.
* If both **pszUnits** and **pUnitsLength** are not NULL, the driver must check the input value of **pUnitsLength** to ensure that there's enough room in the allocated buffer, and then the length of the **pszUnits** string (including terminating NULL character) is passed out through the **pUnitsLength** parameter.

### `unnamedParam9`

[out, optional] **pszDescription** is an optional pointer that the driver returns a NULL-terminated string to that contains the description of what the counter identifier measures.

Can be NULL, in which case the app doesn't need the description info. See more info in the explanation of the **pDescriptionLength** parameter.

### `pDescriptionLength`

[in, out, optional] **pDescriptionLength** is an optional pointer to a variable that receives the size, in bytes, of the NULL-terminated string that the **pszDescription** parameter specifies.

Here are limitations on the values of the **pDescriptionLength** and **pszDescription** parameters:

* **pDescriptionLength** can be NULL, in which case the app doesn't need the unit name or unit name length.
* If **pszDescription** is NULL and **pDescriptionLength** is not NULL, the input value of **pDescriptionLength** is ignored, and the length of the string (including terminating NULL character) must be returned through the **pDescriptionLength** parameter.
* If both **pszDescription** and **pDescriptionLength** are not NULL, the driver must check the input value of **pDescriptionLength** to ensure that there's enough room in the allocated buffer, and then the length of the **pszDescription** string (including terminating NULL character) is passed out through the **pDescriptionLength** parameter.

## Return value

If this routine succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code, including the following:

|Return code|Description|
|--- |--- |
|E_INVALIDARG|An out-of-range device-dependent counter is requested, or a string length is not large enough for a buffer to contain the entire string. Even though all strings used in this function are based on Unicode, they are always in the English locale and are not localized to other locales.|

## Remarks

This function should behave similarly to the [**CheckCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounter) function that supports Microsoft Direct3D 10 and later.

Counters are typically used by tools that capture a frame and play it back multiple times. The pass that records accurate timing info is separate from other passes. In later passes, a different set of counters is used each time.
The priority should be to obtain an accurate correlation of counter results to draw calls, and the overhead incurred during playback can be sacrificed. The driver must insert flush calls or wait-for-idle calls to ensure an accurate correlation.

Typically an app can simultaneously monitor only a small number of possible native counters, which might number in the hundreds. Additionally, the driver must indicate the number of active counters used by monitoring each supported counter ID from the [**D3DDDIQUERYTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) enumeration (both well-known counter IDs and device-specific counter IDs). For example, the driver can indicate that monitoring a **FillRateUtilized** variable requires 3 of the maximum 4 simultaneously active counters (indicated by the **pActiveCounters** parameter). The app can therefore also monitor another counter ID, as long as that counter ID requires one or fewer active counters.

If a counter ID can always be monitored (and it doesn't interfere with monitoring any other counter IDs), the number of simultaneous active counters required by the counter ID can be zero.

## See also

[**CheckCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounter)

[**D3DDDIQUERYTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery)