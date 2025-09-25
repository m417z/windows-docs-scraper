# EV_EXTRA_CERT_CHAIN_POLICY_PARA structure

## Description

The **EV_EXTRA_CERT_CHAIN_POLICY_PARA** structure specifies the parameters that are passed in for EV policy validation. Applications use this structure to pass hints to the API that indicate which of the policy qualifier flags of the extended validation certificates are important to the application.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `dwRootProgramQualifierFlags`

A **DWORD** value that specifies which of the EV policy qualifier bits are required for validation. The value of this parameter can be a Bitwise combination of zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_ROOT_PROGRAM_FLAG_LSC**<br><br>0x40 | Validation of the Locale (L), State (S), and Country (C) fields in the subject name meets Root Program Requirements for display. |
| **CERT_ROOT_PROGRAM_FLAG_ORG**<br><br>0x80 | Validation of the Organization (O) field in the subject name meets Root Program Requirements for display. |
| **CERT_ROOT_PROGRAM_FLAG_SUBJECT_LOGO**<br><br>0x20 | Validation of the Subject logotype meets Root Program Requirements for display. |