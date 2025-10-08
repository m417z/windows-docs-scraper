# MPRESOURCE\_INFO structure

Resource information structure.

## Members

**Scheme**

Type: **MP\_MIDL\_STRING LPWSTR**

Resource scheme identifier such as "file" or "dir".

**Path**

Type: **MP\_MIDL\_STRING LPWSTR**

Absolute path of resource, based on **Scheme**.

**Class**

Type: **MPRESOURCE\_CLASS**

This field is set when the resource is identified as part of the threat. It specifies the resource class, mainly concrete vs. latent. It can be a combination of these possible values:

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| **MP\_RESOURCE\_CLASS\_UNKNOWN**<br>0x0000 | |
| **MP\_RESOURCE\_CLASS\_CONCRETE**<br>0x0001 | Mutually exclusive with **MP\_RESOURCE\_CLASS\_LATENT**.<br> |
| **MP\_RESOURCE\_CLASS\_LATENT**<br>0x0002 | Mutually exclusive with **MP\_RESOURCE\_CLASS\_CONCRETE**.<br> |
| **MP\_RESOURCE\_CLASS\_SAMPLE\_FILE**<br>0x0004 | |
| **MP\_RESOURCE\_CLASS\_SHARED**<br>0x0100 | |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

