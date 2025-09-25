# ICertSrvSetup::InitializeDefaults

## Description

The **InitializeDefaults** method initializes a **CCertSrvSetup** object with default values to enable installation of the Certification Authority role. To install a CA role, this method must be called before using the **CCertSrvSetup** object. For information about default values, see [CASetupProperty](https://learn.microsoft.com/windows/win32/api/casetup/ne-casetup-casetupproperty).

## Parameters

### `bServer` [in]

A value that indicates whether a CA will be installed on the computer. A **VARIANT_TRUE** value indicates that the role will be installed. Neither the Certification Authority nor Certification Authority Web Enrollment roles can be previously installed on the computer.

### `bClient` [in]

A value that indicates whether a Certification Authority Web Enrollment role will be installed on the computer. A **VARIANT_TRUE** value indicates that the role will be installed. This role cannot be previously installed on the computer.

## Remarks

If the policy statement file "CAPolicy.inf" is installed, **InitializeDefaults** processes it.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)