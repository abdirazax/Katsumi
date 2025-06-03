using UnrealBuildTool;

public class KatsumiTarget : TargetRules
{
	public KatsumiTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion  = EngineIncludeOrderVersion.Latest;

		ExtraModuleNames.AddRange( new string[] { "KatsumiCore" } );
	}
}
