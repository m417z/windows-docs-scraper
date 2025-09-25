# RtlCreateAcl function

## Description

The **RtlCreateAcl** routine creates and initializes an access control list (ACL).

## Parameters

### `Acl` [out]

Pointer to a caller-allocated buffer to receive the initialized ACL structure. This buffer must be at least **sizeof**(ACL),

### `AclLength` [in]

Length, in bytes, of the buffer pointed to by the *Acl* parameter. This value must be large enough to contain the ACL header and all of the access-control entries (ACE) to be stored in the ACL. See the following Remarks section for information about calculating the size of an ACL.

### `AclRevision`

ACL revision level of the ACE to be added. Windows version requirements are the following:

| Value | Meaning |
| --- | --- |
| ACL_REVISION | The revision level valid on all Windows versions. |
| ACL_REVISION_DS | **Note** *AceRevision* must be ACL_REVISION_DS if the ACL in *Acl* contains an object-specific ACE. |

## Return value

**RtlCreateAcl** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The ACL was successfully created and initialized. |
| **STATUS_BUFFER_TOO_SMALL** | The new ACL does not fit into the buffer at *Acl*. A larger ACL buffer is required. |
| **STATUS_INVALID_PARAMETER** | The specified revision is not current, or the value of *AclLength* is too large. |

## Remarks

The ACL that is initialized by **RtlCreateAcl** contains no access control entries (ACE). This ACL is empty, as opposed to being a nonexistent ACL. If an empty ACL is applied to an object, the ACL implicitly denies all access to that object. To add ACEs to the ACL, use [RtlAddAccessAllowedAce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdaccessallowedace).

To calculate the size of an ACL, add **sizeof**(ACL) to the size of all the ACEs to be stored in the ACL. To calculate the size of an ACE, add the size of the ACE structure, such as **sizeof**(ACCESS_ALLOWED_ACE), to the length of the SID associated with the ACE, and then subtract the size of the **SidStart** member (which is part of both the ACE structure and the SID). Use the [RtlLengthSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthsid) function to get the length of a specified SID.

The following example shows how to calculate the size of an access-allowed ACE:

```
sizeof (ACCESS_ALLOWED_ACE) - sizeof (ACCESS_ALLOWED_ACE.SidStart)
        + GetLengthSid (pAceSid);
```

To calculate the size of an ACL, use the following algorithm, substituting the appropriate ACE structure in the **sizeof**(ACE) expression:

```
cbAcl = sizeof (ACL);
for (i = 0 ; i < nAceCount ; i++) {
    // subtract ACE.SidStart from the size
    cbAce = sizeof (ACE) - sizeof (DWORD);
    // add this ACE's SID length
    cbAce += GetLengthSid (pAceSid[i]);
    // add the length of each ACE to the total ACL length
    cbAcl += cbAce;
}
```

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[RtlAddAccessAllowedAce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdaccessallowedace)

[RtlLengthSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthsid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)