# ADS_CHASE_REFERRALS_ENUM enumeration

## Description

The **ADS_CHASE_REFERRALS_ENUM** enumeration specifies if, and how, referral chasing occurs. When a server determines that other servers hold relevant data, in part or as a whole, it may refer the client to another server to obtain the result. Referral chasing is the action taken by a client to contact the referred-to server to continue the directory search.

## Constants

### `ADS_CHASE_REFERRALS_NEVER:0`

The client should never chase the referred-to server. Setting this option prevents a client from contacting other servers in a referral process.

### `ADS_CHASE_REFERRALS_SUBORDINATE:0x20`

The client chases only subordinate referrals which are a subordinate naming context in a directory tree. For example, if the base search is requested for "DC=Fabrikam,DC=Com", and the server returns a result set and a referral of "DC=Sales,DC=Fabrikam,DC=Com" on the AdbSales server, the client can contact the AdbSales server to continue the search. The ADSI LDAP provider always turns off this flag for paged searches.

### `ADS_CHASE_REFERRALS_EXTERNAL:0x40`

The client chases external referrals. For example, a client requests server A to perform a search for "DC=Fabrikam,DC=Com". However, server A does not contain the object, but knows that an independent server, B, owns it. It then refers the client to server B.

### `ADS_CHASE_REFERRALS_ALWAYS`

Referrals are chased for either the subordinate or external type.

## Remarks

Use the constants of this enumeration to set up search preferences for referral chasing. The action amounts to assigning the appropriate fields of the [ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info) structure with elements of the **ADS_CHASE_REFERRALS_ENUM** and [ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum) enumerations. The values of this enumeration can also be used with [IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions) to specify whether referral chasing should take place when enumerating the objects under a container object.

The [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) interface has a partial implementation of **ADS_CHASE_REFERRALS_ENUM** through the [ChaseReferral](https://learn.microsoft.com/windows/desktop/ADSI/iadsnametranslate-property-methods) property. If the **ChaseReferral** property is set to zero (0), it is the same as specifying **ADS_CHASE_REFERRALS_NEVER** (0). If a nonzero value is used, it is the same as specifying **ADS_CHASE_REFERRALS_ALWAYS** (0x60). **IADsNameTranslate** does not implement the **ADS_CHASE_REFERRALS_SUBORDINATE** (0x20) or **ADS_CHASE_REFERRALS_EXTERNAL** (0x40) options.

The ADSI LDAP provider supports external referrals for paged searches, but does not support subordinate referrals during paging.

**Note** Because VBScript cannot read data from a type library, VBScript applications do not understand the symbolic constants as defined above. You should use the numerical constants instead to set the appropriate flags in your VBScript applications. If you want to use the symbolic constants as a good programming practice, you should make explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_SEARCHPREF_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_searchpref_enum)

[ADS_SEARCHPREF_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_searchpref_info)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)

[IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions)