all::
	xcodebuild clean build CODE_SIGN_IDENTITY="" CODE_SIGNING_REQUIRED=NO CODE_SIGNING_ALLOWED=NO PRODUCT_BUNDLE_IDENTIFIER="vn.hoahuynh.olver" -sdk iphoneos -configuration Debug -quiet
	ln -sf build/Debug-iphoneos Payload
	zip -r9q OlVer_V1.0_fix.ipa Payload/OlVer.app/
	rm -rf clean build Payload
	
clean::
	rm -rf clean build Payload OlVer_V1.0_fix.ipa

