# IOCSPCAConfigurationCollection::DeleteCAConfiguration

## Description

The **DeleteCAConfiguration** method removes a named [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration from the configuration set.

## Parameters

### `bstrIdentifier` [in]

A string that contains the name for the [IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration) object.

## Remarks

The *bstrIdentifier* value must be one previously set by the [CreateCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfigurationcollection-createcaconfiguration) method.

## See also

[IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection)