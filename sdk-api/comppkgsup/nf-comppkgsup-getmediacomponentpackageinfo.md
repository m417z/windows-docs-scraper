# GetMediaComponentPackageInfo function

## Description

Returns a list of properties for all media codecs installed on the system that meet the specified requirements.

## Parameters

### `trustedOnly` [in]

True if the query should only return properties for packages that run in the app's process space; false if the query should include packages that run in a separate app service.

### `category` [in]

A string that specifies the category of packages that should be included in the results.

### `codecPropertiesVector` [out]

A list of [IPropertySet](https://learn.microsoft.com/uwp/api/windows.foundation.collections.ipropertyset) objects representing the properties of the installed media component packages that meet the specified criteria.

## Return value

Returns S_OK on successful completion.