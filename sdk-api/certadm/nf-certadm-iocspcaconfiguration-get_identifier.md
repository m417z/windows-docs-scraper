# IOCSPCAConfiguration::get_Identifier

## Description

The **Identifier** property gets a name for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) configuration. The default implementations of [IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin) and [IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection) set this value.

This property is read-only.

## Parameters

## Remarks

The name returned in *pVal* corresponds to the name used in the *bstrIdentifier* parameter of the [CreateCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfigurationcollection-createcaconfiguration) method.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)