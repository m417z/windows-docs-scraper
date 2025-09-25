# SecPkgContext_Flags structure

## Description

The **SecPkgContext_Flags** structure contains information about the flags in the current [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This structure is returned by [QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa).

## Members

### `Flags`

Flag values for the current security context. These values correspond to the flags negotiated by the [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) and [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) functions.