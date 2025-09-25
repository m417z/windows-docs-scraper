# ObjectTypeIsValid function

## Description

The **ObjectTypeIsValid** function determines whether an element of the ObjectType enumeration represents a valid object type.

## Parameters

### `type`

Type: **[ObjectType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-objecttype)**

Element of the ObjectType enumeration to be tested.

## Return value

Type: **BOOL**

If objectType is equal to ObjectTypeInvalid, this function returns **FALSE**.

 If objectType is equal to any other element of the ObjectType enumeration, this function returns **TRUE**.