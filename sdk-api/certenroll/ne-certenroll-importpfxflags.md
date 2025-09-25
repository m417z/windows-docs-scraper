# ImportPFXFlags enumeration

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

Flags to use when importing a PFX certificate.

## Constants

### `ImportNone:0`

None

### `ImportMachineContext:0x1`

Import the PFX certificate into the machine certificate store; otherwise install to the user certificate store.

### `ImportForceOverwrite:0x2`

Overwrite existing certificate, if exists.

### `ImportSilent:0x4`

Silently perform the operation (do not show a user interface).

### `ImportSaveProperties:0x8`

Save Properties on the imported PFX file.

### `ImportExportable:0x10`

Import the PFX certificate’s private key as exportable

### `ImportExportableEncrypted:0x20`

Import the PFX certificate’s private key as exportable and encrypted.

### `ImportNoUserProtected:0x40`

Import the PFX certificate’s private key to not require consent.

### `ImportUserProtected:0x80`

Import the PFX certificate’s private key to require consent without a password.

### `ImportUserProtectedHigh:0x100`

Import the PFX certificate’s private key to require consent with a password.

### `ImportInstallCertificate:0x200`

Install the PFX certificate to the certificate store.

### `ImportInstallChain:0x400`

Install the PFX certificate’s chain to the certificate store.

### `ImportInstallChainAndRoot:0x800`

Install the PFX certificate’s chain and root to the certificate store.