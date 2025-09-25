# IBDA_ConditionalAccess::get_SmartCardInfo

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SmartCardInfo** method retrieves information about the smart card.

## Parameters

### `pbstrCardName` [out]

Receives a string containing the card name. When the string is no longer required, call the **SysFreeString** function to free it.

### `pbstrCardManufacturer` [out]

Receives a string containing the name of the card manufacturer. When the string is no longer required, call the **SysFreeString** function to free it.

### `pfDaylightSavings` [out]

Receives a value indicating whether daylight savings is in effect. If the value is VARIANT_TRUE, daylight savings is in effect. If the value is VARIANT_FALSE, daylight savings is not in effect.

### `pbyRatingRegion` [out]

Receives a value indicating the rating region.

### `plTimeZoneOffsetMinutes` [out]

Receives the time zone offset in minutes.

### `pbstrLanguage` [out]

Receives a string indicating the language. When the string is no longer required, call the **SysFreeString** function to free it.

### `pEALocationCode` [out]

Pointer to a buffer that receives the emergency alert location code information. The buffer size must be at least `sizeof(EALocationCodeType)`. The method writes a structure of type [EALocationCodeType](https://learn.microsoft.com/windows/desktop/api/bdaiface/ns-bdaiface-ealocationcodetype) to the buffer. The structure specifies the location code scheme (for example, SCTE 18), state, county, and county subdivision for the emergency alert.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IBDA_ConditionalAccess Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_conditionalaccess)