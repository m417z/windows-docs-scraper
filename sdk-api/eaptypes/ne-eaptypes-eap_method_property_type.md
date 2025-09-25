# EAP_METHOD_PROPERTY_TYPE enumeration

## Description

The **EAP_METHOD_PROPERTY_TYPE** enumeration specifies the set of possible EAP method properties.

## Constants

### `emptPropCipherSuiteNegotiation:0`

Boolean method property for specifying the support for cipher suite negotiation.

### `emptPropMutualAuth`

Boolean method property for specifying the support for mutual authentication.

### `emptPropIntegrity`

Boolean method property for specifying the support for message integrity.

### `emptPropReplayProtection`

Boolean method property for specifying the support for replay protection.

### `emptPropConfidentiality`

Boolean method property for specifying the support for encrypting EAP messages.

### `emptPropKeyDerivation`

Boolean method property for specifying the support for deriving exportable keying materials.

### `emptPropKeyStrength64`

Boolean method property for specifying the support for key length of at least 64 bits.

### `emptPropKeyStrength128`

Boolean method property for specifying the support for key length of at least 128 bits.

### `emptPropKeyStrength256`

Boolean method property for specifying the support for key length of at least 256 bits.

### `emptPropKeyStrength512`

Boolean method property for specifying the support for key length of at least 512 bits.

### `emptPropKeyStrength1024`

Boolean method property for specifying the support for key length of at least 1024 bits.

### `emptPropDictionaryAttackResistance`

Boolean method property for specifying the support for preventing offline attack that has a work factor based on the number of passwords in an attacker’s dictionary.

### `emptPropFastReconnect`

Boolean method property for specifying the support for establishing a security association in a smaller number of round trips by using the cached parameters of a previous successful authentication.

### `emptPropCryptoBinding`

Boolean method property for specifying the support for preventing man-in-the-middle attacks in a tunneling method. The method supporting cryptobinding demonstrates to the EAP server that a single entity has acted as the EAP peer for all methods executed within a tunnel method.

### `emptPropSessionIndependence`

Boolean method property for specifying that passive attacks (such as capture of the EAP conversation) or active attacks (including compromise of the MSK or EMSK) do not compromise subsequent or prior MSKs or EMSKs.

### `emptPropFragmentation`

Boolean method property for specifying the support for fragmentation and reassembly of EAP packets exceeding the MTU size.

### `emptPropChannelBinding`

Boolean method property for specifying the ability to communicate integrity-protected channel properties, such as endpoint identifiers, which can be compared to values communicated using out of band mechanisms, such as an Authentication, Authorization, and Accounting (AAA) protocol or the lower layer protocol.

### `emptPropNap`

Boolean method property for specifying the support for Network Access Protection.

### `emptPropStandalone`

Boolean method property for specifying the support for execution of the method on a standalone computer.

### `emptPropMppeEncryption`

Boolean method property for specifying the support for Microsoft Point-to-Point Encryption (MPPE) protocol encryption.

### `emptPropTunnelMethod`

Boolean method property for specifying the ability of the method to tunnel other EAP methods.

### `emptPropSupportsConfig`

Boolean method property for specifying the support for method configuration and user interface.

### `emptPropCertifiedMethod`

Boolean method property for specifying if the method was certified by the EAP Certification Program (ECP).

### `emptPropHiddenMethod`

Boolean method property for specifying a hidden method.

### `emptPropMachineAuth`

Boolean method property for specifying the support for computer authentication.

### `emptPropUserAuth`

Boolean method property for specifying the support for user authentication.

### `emptPropIdentityPrivacy`

Boolean method property for specifying the support for identity privacy.

### `emptPropMethodChaining`

Boolean method property for specifying the support for method chaining.

### `emptPropSharedStateEquivalence`

Boolean method property for specifying the support for shared state equivalence as defined in RFC4017.

### `emptLegacyMethodPropertyFlag:31`

**DWORD** property method for values sent prior to Windows 7.

### `emptPropVendorSpecific`

String property method for specifying any vendor-specific property of the EAP method.

### `v1_enum`

## See also

[EAPHost Supplicant Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-enumerations)

[EAP_METHOD_PROPERTY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property)

[EAP_METHOD_PROPERTY_VALUE_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_method_property_value_type)