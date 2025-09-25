# IOCSPCAConfiguration::get_ErrorCode

## Description

The **ErrorCode** property gets a code that identifies an error condition in a CA configuration. The default implementations of [IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin) and [IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection) set the initial error-condition value.

This property is read-only.

## Parameters

## Remarks

The OCSP responder service returns an error code when it encounters a problem with a configuration. For the definition of a returned code, see Winerror.h in the Microsoft Windows Software Development Kit (SDK).

An **OCSPCAConfiguration** object internally stores the error code as an **HRESULT** with an initial value of **E_PENDING**. When [IOCSPAdmin::SetConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspadmin-setconfiguration) is called, the error code is reset to **E_PENDING**.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)