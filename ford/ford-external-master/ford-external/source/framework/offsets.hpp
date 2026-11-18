#pragma once
#include <cstdint>

/*
 * Roblox Offsets
 * ------------------------------------------------------------
 * Version     : version-2c6fd5e09aaf4cfa
 * Dumper      : RbxDumperV2 v2.2.5
 * Dumped At   : 07:30 17/11/2026
 * Source      : https://offsets.imtheo.lol
 * Total       : 394 offsets
 *
 * Note: fields named `Pointer` are module-relative base
 * addresses, not instance member offsets. Values of 0 were
 * unresolved in this dump.
 * ------------------------------------------------------------
 */

namespace Offsets
{
    namespace TaskScheduler
    {
        constexpr std::uintptr_t Pointer = 148528536;
        constexpr std::uintptr_t JobStart = 200;
        constexpr std::uintptr_t JobEnd = 208;
        constexpr std::uintptr_t JobName = 24;
        constexpr std::uintptr_t MaxFPS = 176;
    }  // namespace TaskScheduler

    namespace VisualEngine
    {
        constexpr std::uintptr_t Pointer = 143223704;
        constexpr std::uintptr_t Dimensions = 2832;
        constexpr std::uintptr_t ViewMatrix = 432;
        constexpr std::uintptr_t RenderView = 3152;
        constexpr std::uintptr_t FakeDataModel = 2800;
    }  // namespace VisualEngine

    namespace FakeDataModel
    {
        constexpr std::uintptr_t Pointer = 148988776;
        constexpr std::uintptr_t RealDataModel = 504;
    }  // namespace FakeDataModel

    namespace RenderView
    {
        constexpr std::uintptr_t LightingValid = 0;
        constexpr std::uintptr_t SkyValid = 0;
        constexpr std::uintptr_t VisualEngine = 0;
        constexpr std::uintptr_t DeviceD3D11 = 0;
    }  // namespace RenderView

    namespace ScriptContext
    {
        constexpr std::uintptr_t RequireBypass = 0;
    }

    namespace ModuleScript
    {
        constexpr std::uintptr_t IsCoreScript = 0;
        constexpr std::uintptr_t GUID = 184;
        constexpr std::uintptr_t Hash = 0;
        constexpr std::uintptr_t ByteCode = 0;
    }  // namespace ModuleScript

    namespace MouseService
    {
        constexpr std::uintptr_t SensitivityPointer = 0;
        constexpr std::uintptr_t InputObject = 232;
        constexpr std::uintptr_t InputObject2 = 248;
        constexpr std::uintptr_t MousePosition = 188;
    }  // namespace MouseService

    namespace PlayerConfigurer
    {
        constexpr std::uintptr_t Pointer = 0;
    }

    namespace Instance
    {
        constexpr std::uintptr_t This = 8;
        constexpr std::uintptr_t NameContainer = 104;
        constexpr std::uintptr_t Name = 0;
        constexpr std::uintptr_t ChildrenStart = 112;
        constexpr std::uintptr_t ChildrenEnd = 8;
        constexpr std::uintptr_t Parent = 96;
        constexpr std::uintptr_t ClassDescriptor = 24;
        constexpr std::uintptr_t ClassName = 8;
        constexpr std::uintptr_t ClassBase = 440;
    }  // namespace Instance

    namespace Misc
    {
        constexpr std::uintptr_t StringLength = 16;
        constexpr std::uintptr_t Adornee = 216;
        constexpr std::uintptr_t Value = 160;
        constexpr std::uintptr_t AnimationId = 168;
    }  // namespace Misc

    namespace HandleAdornment
    {
        constexpr std::uintptr_t CFrame = 256;
    }

    namespace DataModel
    {
        constexpr std::uintptr_t PlaceId = 416;
        constexpr std::uintptr_t GameId = 408;
        constexpr std::uintptr_t CreatorId = 400;
        constexpr std::uintptr_t GameLoaded = 1464;
        constexpr std::uintptr_t JobId = 264;
        constexpr std::uintptr_t Workspace = 360;
        constexpr std::uintptr_t ScriptContext = 1088;
        constexpr std::uintptr_t PlaceVersion = 444;
        constexpr std::uintptr_t ServerIP = 1440;
        constexpr std::uintptr_t ToRenderView1 = 472;
        constexpr std::uintptr_t ToRenderView2 = 8;
        constexpr std::uintptr_t ToRenderView3 = 40;
        constexpr std::uintptr_t PrimitiveCount = 1072;
    }  // namespace DataModel

    namespace RunService
    {
        constexpr std::uintptr_t HeartbeatTask = 167480;
        constexpr std::uintptr_t HeartbeatFPS = 190;
    }  // namespace RunService

    namespace RenderJob
    {
        constexpr std::uintptr_t RenderView = 480;
        constexpr std::uintptr_t FakeDataModel = 56;
        constexpr std::uintptr_t RealDataModel = 496;
    }  // namespace RenderJob

    namespace Workspace
    {
        constexpr std::uintptr_t World = 1016;
        constexpr std::uintptr_t ReadOnlyGravity = 2504;
        constexpr std::uintptr_t DistributedGameTime = 1216;
        constexpr std::uintptr_t CurrentCamera = 1184;
    }  // namespace Workspace

    namespace World
    {
        constexpr std::uintptr_t Gravity = 536;
        constexpr std::uintptr_t worldStepsPerSec = 2152;
        constexpr std::uintptr_t FallenPartsDestroyHeight = 524;
        constexpr std::uintptr_t AirProperties = 560;
        constexpr std::uintptr_t Primitives = 672;
    }  // namespace World

    namespace AirProperties
    {
        constexpr std::uintptr_t AirDensity = 24;
        constexpr std::uintptr_t GlobalWind = 60;
    }  // namespace AirProperties

    namespace Terrain
    {
        constexpr std::uintptr_t GrassLength = 472;
        constexpr std::uintptr_t WaterReflectance = 480;
        constexpr std::uintptr_t WaterTransparency = 484;
        constexpr std::uintptr_t WaterWaveSize = 488;
        constexpr std::uintptr_t WaterWaveSpeed = 492;
        constexpr std::uintptr_t WaterColor = 456;
        constexpr std::uintptr_t MaterialColors = 1184;
    }  // namespace Terrain

    namespace MaterialColors
    {
        constexpr std::uintptr_t Asphalt = 48;
        constexpr std::uintptr_t Basalt = 39;
        constexpr std::uintptr_t Brick = 15;
        constexpr std::uintptr_t Cobblestone = 51;
        constexpr std::uintptr_t Concrete = 12;
        constexpr std::uintptr_t CrackedLava = 45;
        constexpr std::uintptr_t Glacier = 27;
        constexpr std::uintptr_t Grass = 6;
        constexpr std::uintptr_t Ground = 42;
        constexpr std::uintptr_t Ice = 54;
        constexpr std::uintptr_t LeafyGrass = 57;
        constexpr std::uintptr_t Limestone = 63;
        constexpr std::uintptr_t Mud = 36;
        constexpr std::uintptr_t Pavement = 66;
        constexpr std::uintptr_t Rock = 24;
        constexpr std::uintptr_t Salt = 60;
        constexpr std::uintptr_t Sand = 18;
        constexpr std::uintptr_t Sandstone = 33;
        constexpr std::uintptr_t Slate = 9;
        constexpr std::uintptr_t Snow = 30;
        constexpr std::uintptr_t WoodPlanks = 21;
    }  // namespace MaterialColors

    namespace Sound
    {
        constexpr std::uintptr_t SoundId = 176;
        constexpr std::uintptr_t RollOffMaxDistance = 256;
        constexpr std::uintptr_t RollOffMinDistance = 260;
        constexpr std::uintptr_t PlaybackSpeed = 252;
        constexpr std::uintptr_t Volume = 272;
        constexpr std::uintptr_t SoundGroup = 208;
        constexpr std::uintptr_t IsPlaying = 280;
        constexpr std::uintptr_t Looped = 277;
    }  // namespace Sound

    namespace SpawnLocation
    {
        constexpr std::uintptr_t AllowTeamChangeOnTouch = 472;
        constexpr std::uintptr_t Enabled = 473;
        constexpr std::uintptr_t Neutral = 474;
        constexpr std::uintptr_t ForcefieldDuration = 464;
        constexpr std::uintptr_t TeamColor = 468;
    }  // namespace SpawnLocation

    namespace SurfaceAppearance
    {
        constexpr std::uintptr_t AlphaMode = 472;
        constexpr std::uintptr_t Color = 448;
        constexpr std::uintptr_t ColorMap = 176;
        constexpr std::uintptr_t EmissiveMaskContent = 224;
        constexpr std::uintptr_t EmissiveStrength = 476;
        constexpr std::uintptr_t EmissiveTint = 460;
        constexpr std::uintptr_t MetalnessMap = 272;
        constexpr std::uintptr_t NormalMap = 320;
        constexpr std::uintptr_t RoughnessMap = 368;
    }  // namespace SurfaceAppearance

    namespace ParticleEmitter
    {
        constexpr std::uintptr_t Brightness = 516;
        constexpr std::uintptr_t LightEmission = 544;
        constexpr std::uintptr_t LightInfluence = 548;
        constexpr std::uintptr_t Texture = 424;
        constexpr std::uintptr_t ZOffset = 588;
        constexpr std::uintptr_t Lifetime = 476;
        constexpr std::uintptr_t Rate = 560;
        constexpr std::uintptr_t Rotation = 492;
        constexpr std::uintptr_t RotSpeed = 484;
        constexpr std::uintptr_t Speed = 500;
        constexpr std::uintptr_t SpreadAngle = 508;
        constexpr std::uintptr_t Acceleration = 456;
        constexpr std::uintptr_t Drag = 520;
        constexpr std::uintptr_t TimeScale = 580;
        constexpr std::uintptr_t VelocityInheritance = 584;
    }  // namespace ParticleEmitter

    namespace Beam
    {
        constexpr std::uintptr_t Brightness = 360;
        constexpr std::uintptr_t LightEmission = 372;
        constexpr std::uintptr_t LightInfluence = 376;
        constexpr std::uintptr_t Texture = 296;
        constexpr std::uintptr_t TextureLength = 388;
        constexpr std::uintptr_t TextureSpeed = 396;
        constexpr std::uintptr_t ZOffset = 408;
        constexpr std::uintptr_t Attachment0 = 328;
        constexpr std::uintptr_t Attachment1 = 344;
        constexpr std::uintptr_t CurveSize0 = 364;
        constexpr std::uintptr_t CurveSize1 = 368;
        constexpr std::uintptr_t Width0 = 400;
        constexpr std::uintptr_t Width1 = 404;
    }  // namespace Beam

    namespace Player
    {
        constexpr std::uintptr_t LocalPlayer = 280;
        constexpr std::uintptr_t UserId = 184;
        constexpr std::uintptr_t DisplayName = 288;
        constexpr std::uintptr_t HealthDisplayDistance = 928;
        constexpr std::uintptr_t NameDisplayDistance = 944;
        constexpr std::uintptr_t ModelInstance = 672;
        constexpr std::uintptr_t Team = 736;
        constexpr std::uintptr_t TeamColor = 952;
        constexpr std::uintptr_t LocaleId = 256;
        constexpr std::uintptr_t AccountAge = 868;
        constexpr std::uintptr_t MinZoomDistance = 884;
        constexpr std::uintptr_t MaxZoomDistance = 880;
        constexpr std::uintptr_t CameraMode = 888;
        constexpr std::uintptr_t Mouse = 4728;
    }  // namespace Player

    namespace Team
    {
        constexpr std::uintptr_t BrickColor = 160;
    }

    namespace Humanoid
    {
        constexpr std::uintptr_t Health = 388;
        constexpr std::uintptr_t MaxHealth = 416;
        constexpr std::uintptr_t Walkspeed = 456;
        constexpr std::uintptr_t WalkspeedCheck = 924;
        constexpr std::uintptr_t JumpPower = 412;
        constexpr std::uintptr_t JumpHeight = 408;
        constexpr std::uintptr_t HipHeight = 392;
        constexpr std::uintptr_t MaxSlopeAngle = 420;
        constexpr std::uintptr_t SeatPart = 240;
        constexpr std::uintptr_t HumanoidRootPart = 1120;
        constexpr std::uintptr_t CameraOffset = 272;
        constexpr std::uintptr_t HealthDisplayDistance = 380;
        constexpr std::uintptr_t NameDisplayDistance = 424;
        constexpr std::uintptr_t DisplayDistanceType = 372;
        constexpr std::uintptr_t HealthDisplayType = 384;
        constexpr std::uintptr_t NameOcclusion = 428;
        constexpr std::uintptr_t DisplayName = 160;
        constexpr std::uintptr_t MoveDirection = 308;
        constexpr std::uintptr_t RigType = 440;
        constexpr std::uintptr_t Jump = 468;
        constexpr std::uintptr_t Sit = 470;
        constexpr std::uintptr_t PlatformStand = 469;
        constexpr std::uintptr_t UseJumpPower = 473;
        constexpr std::uintptr_t AutomaticScalingEnabled = 462;
        constexpr std::uintptr_t BreakJointsOnDeath = 464;
        constexpr std::uintptr_t EvaluateStateMachine = 465;
        constexpr std::uintptr_t RequiresNeck = 470;
        constexpr std::uintptr_t AutoJumpEnabled = 460;
        constexpr std::uintptr_t AutoRotate = 461;
        constexpr std::uintptr_t IsWalking = 2622;
        constexpr std::uintptr_t MoveToPoint = 344;
        constexpr std::uintptr_t MoveToPart = 256;
        constexpr std::uintptr_t WalkTimer = 0;
        constexpr std::uintptr_t HumanoidState = 2216;
        constexpr std::uintptr_t HumanoidStateID = 32;
        constexpr std::uintptr_t FloorMaterial = 376;
        constexpr std::uintptr_t TargetPoint = 320;
        constexpr std::uintptr_t PlatformStatePointer = 3275782036;
    }  // namespace Humanoid

    namespace Seat
    {
        constexpr std::uintptr_t Occupant = 512;
    }

    namespace VehicleSeat
    {
        constexpr std::uintptr_t MaxSpeed = 528;
        constexpr std::uintptr_t SteerFloat = 532;
        constexpr std::uintptr_t ThrottleFloat = 536;
        constexpr std::uintptr_t Torque = 540;
        constexpr std::uintptr_t TurnSpeed = 544;
    }  // namespace VehicleSeat

    namespace StatsItem
    {
        constexpr std::uintptr_t Value = 47421;
    }

    namespace Tool
    {
        constexpr std::uintptr_t Tooltip = 1104;
        constexpr std::uintptr_t TextureId = 840;
        constexpr std::uintptr_t Grip = 1172;
        constexpr std::uintptr_t Enabled = 1185;
        constexpr std::uintptr_t CanBeDropped = 1184;
        constexpr std::uintptr_t ManualActivationOnly = 1186;
        constexpr std::uintptr_t RequiresHandle = 1187;
    }  // namespace Tool

    namespace Clothing
    {
        constexpr std::uintptr_t Template = 232;
        constexpr std::uintptr_t Color3 = 264;
    }  // namespace Clothing

    namespace CharacterMesh
    {
        constexpr std::uintptr_t BaseTextureId = 176;
        constexpr std::uintptr_t OverlayTextureId = 272;
        constexpr std::uintptr_t MeshId = 224;
        constexpr std::uintptr_t BodyPart = 304;
    }  // namespace CharacterMesh

    namespace Camera
    {
        constexpr std::uintptr_t Position = 228;
        constexpr std::uintptr_t Rotation = 192;
        constexpr std::uintptr_t CameraSubject = 176;
        constexpr std::uintptr_t FieldOfView = 296;
        constexpr std::uintptr_t ImagePlaneDepth = 724;
        constexpr std::uintptr_t CameraType = 288;
        constexpr std::uintptr_t Viewport = 644;
        constexpr std::uintptr_t ViewportSize = 708;
    }  // namespace Camera

    namespace BasePart
    {
        constexpr std::uintptr_t Primitive = 376;
        constexpr std::uintptr_t Transparency = 280;
        constexpr std::uintptr_t Color3 = 284;
        constexpr std::uintptr_t Shape = 416;
        constexpr std::uintptr_t Massless = 290;
        constexpr std::uintptr_t CastShadow = 288;
        constexpr std::uintptr_t Locked = 289;
        constexpr std::uintptr_t Reflectance = 244;
    }  // namespace BasePart

    namespace Primitive
    {
        constexpr std::uintptr_t Position = 212;
        constexpr std::uintptr_t Validate = 6;
        constexpr std::uintptr_t Owner = 544;
        constexpr std::uintptr_t Size = 452;
        constexpr std::uintptr_t Rotation = 176;
        constexpr std::uintptr_t Flags = 446;
        constexpr std::uintptr_t Material = 598;
        constexpr std::uintptr_t AssemblyLinearVelocity = 224;
        constexpr std::uintptr_t AssemblyAngularVelocity = 236;
    }  // namespace Primitive

    namespace PrimitiveFlags
    {
        constexpr std::uintptr_t Anchored = 2;
        constexpr std::uintptr_t CanCollide = 8;
        constexpr std::uintptr_t CanTouch = 16;
        constexpr std::uintptr_t CanQuery = 32;
    }  // namespace PrimitiveFlags

    namespace MeshPart
    {
        constexpr std::uintptr_t MeshId = 760;
        constexpr std::uintptr_t Texture = 808;
        constexpr std::uintptr_t MeshSize = 528;
    }  // namespace MeshPart

    namespace Model
    {
        constexpr std::uintptr_t PrimaryPart = 576;
        constexpr std::uintptr_t Scale = 300;
    }  // namespace Model

    namespace SpecialMesh
    {
        constexpr std::uintptr_t Scale = 172;
        constexpr std::uintptr_t MeshId = 224;
    }  // namespace SpecialMesh

    namespace Attachment
    {
        constexpr std::uintptr_t Position = 172;
    }

    namespace JointInstance
    {
        constexpr std::uintptr_t Part0 = 256;
        constexpr std::uintptr_t Part1 = 272;
    }  // namespace JointInstance

    namespace WeldConstraint
    {
        constexpr std::uintptr_t Part0 = 160;
        constexpr std::uintptr_t Part1 = 176;
    }  // namespace WeldConstraint

    namespace UnionOperation
    {
        constexpr std::uintptr_t AssetId = 760;
    }

    namespace PlayerMouse
    {
        constexpr std::uintptr_t Workspace = 312;
        constexpr std::uintptr_t Icon = 176;
    }  // namespace PlayerMouse

    namespace GuiObject
    {
        constexpr std::uintptr_t ScreenGui_Enabled = 1037;
        constexpr std::uintptr_t Position = 680;
        constexpr std::uintptr_t Size = 712;
        constexpr std::uintptr_t Visible = 1840;
        constexpr std::uintptr_t Image = 1648;
        constexpr std::uintptr_t Text = 2608;
        constexpr std::uintptr_t RichText = 1992;
        constexpr std::uintptr_t BackgroundColor3 = 728;
        constexpr std::uintptr_t BorderColor3 = 740;
        constexpr std::uintptr_t TextColor3 = 2784;
        constexpr std::uintptr_t LayoutOrder = 788;
        constexpr std::uintptr_t ZIndex = 828;
        constexpr std::uintptr_t BackgroundTransparency = 740;
        constexpr std::uintptr_t Rotation = 208;
    }  // namespace GuiObject

    namespace GuiBase2D
    {
        constexpr std::uintptr_t AbsoluteSize = 0;
        constexpr std::uintptr_t AbsolutePosition = 244;
        constexpr std::uintptr_t AbsoluteRotation = 208;
    }  // namespace GuiBase2D

    namespace UserInputService
    {
        constexpr std::uintptr_t WindowInputState = 648;
    }

    namespace WindowInputState
    {
        constexpr std::uintptr_t CurrentTextBox = 72;
        constexpr std::uintptr_t CapsLock = 64;
    }  // namespace WindowInputState

    namespace Textures
    {
        constexpr std::uintptr_t Decal_Texture = 456;
        constexpr std::uintptr_t Texture_Texture = 456;
    }  // namespace Textures

    namespace Lighting
    {
        constexpr std::uintptr_t ClockTime = 176;
        constexpr std::uintptr_t Brightness = 256;
        constexpr std::uintptr_t EnvironmentDiffuseScale = 260;
        constexpr std::uintptr_t EnvironmentSpecularScale = 264;
        constexpr std::uintptr_t FogStart = 280;
        constexpr std::uintptr_t FogEnd = 276;
        constexpr std::uintptr_t FogColor = 220;
        constexpr std::uintptr_t Ambient = 184;
        constexpr std::uintptr_t OutdoorAmbient = 232;
        constexpr std::uintptr_t ColorShift_Bottom = 196;
        constexpr std::uintptr_t ColorShift_Top = 208;
        constexpr std::uintptr_t ExposureCompensation = 268;
        constexpr std::uintptr_t GeographicLatitude = 284;
        constexpr std::uintptr_t LightColor = 332;
        constexpr std::uintptr_t GradientTop = 320;
        constexpr std::uintptr_t LightDirection = 344;
        constexpr std::uintptr_t GradientBottom = 384;
        constexpr std::uintptr_t GlobalShadows = 306;
        constexpr std::uintptr_t MoonPosition = 372;
        constexpr std::uintptr_t SunPosition = 360;
        constexpr std::uintptr_t Source = 356;
        constexpr std::uintptr_t Sky = 440;
    }  // namespace Lighting

    namespace Sky
    {
        constexpr std::uintptr_t SkyboxBk = 224;
        constexpr std::uintptr_t SkyboxDn = 272;
        constexpr std::uintptr_t SkyboxFt = 320;
        constexpr std::uintptr_t SkyboxLf = 368;
        constexpr std::uintptr_t SkyboxRt = 416;
        constexpr std::uintptr_t SkyboxUp = 464;
        constexpr std::uintptr_t SunAngularSize = 548;
        constexpr std::uintptr_t MoonAngularSize = 556;
        constexpr std::uintptr_t SunTextureId = 512;
        constexpr std::uintptr_t MoonTextureId = 176;
        constexpr std::uintptr_t SkyboxOrientation = 544;
        constexpr std::uintptr_t StarCount = 560;
    }  // namespace Sky

    namespace Atmosphere
    {
        constexpr std::uintptr_t Density = 184;
        constexpr std::uintptr_t Offset = 196;
        constexpr std::uintptr_t Color = 160;
        constexpr std::uintptr_t Decay = 172;
        constexpr std::uintptr_t Glare = 188;
        constexpr std::uintptr_t Haze = 192;
    }  // namespace Atmosphere

    namespace BloomEffect
    {
        constexpr std::uintptr_t Intensity = 160;
        constexpr std::uintptr_t Size = 164;
        constexpr std::uintptr_t Threshold = 168;
        constexpr std::uintptr_t Enabled = 152;
    }  // namespace BloomEffect

    namespace DepthOfFieldEffect
    {
        constexpr std::uintptr_t FocusDistance = 164;
        constexpr std::uintptr_t FarIntensity = 160;
        constexpr std::uintptr_t NearIntensity = 172;
        constexpr std::uintptr_t InFocusRadius = 168;
        constexpr std::uintptr_t Enabled = 152;
    }  // namespace DepthOfFieldEffect

    namespace SunRaysEffect
    {
        constexpr std::uintptr_t Intensity = 160;
        constexpr std::uintptr_t Spread = 164;
        constexpr std::uintptr_t Enabled = 152;
    }  // namespace SunRaysEffect

    namespace ColorCorrectionEffect
    {
        constexpr std::uintptr_t Brightness = 220;
        constexpr std::uintptr_t Contrast = 228;
        constexpr std::uintptr_t TintColor = 208;
        constexpr std::uintptr_t Enabled = 152;
    }  // namespace ColorCorrectionEffect

    namespace ColorGradingEffect
    {
        constexpr std::uintptr_t TonemapperPreset = 160;
        constexpr std::uintptr_t Enabled = 152;
    }  // namespace ColorGradingEffect

    namespace BlurEffect
    {
        constexpr std::uintptr_t Size = 160;
        constexpr std::uintptr_t Enabled = 152;
    }  // namespace BlurEffect

    namespace ProximityPrompt
    {
        constexpr std::uintptr_t ActionText = 152;
        constexpr std::uintptr_t ObjectText = 184;
        constexpr std::uintptr_t HoldDuration = 264;
        constexpr std::uintptr_t MaxActivationDistance = 272;
        constexpr std::uintptr_t KeyCode = 268;
        constexpr std::uintptr_t GamepadKeyCode = 260;
        constexpr std::uintptr_t Enabled = 286;
        constexpr std::uintptr_t RequiresLineOfSight = 287;
    }  // namespace ProximityPrompt

    namespace ClickDetector
    {
        constexpr std::uintptr_t MaxActivationDistance = 208;
        constexpr std::uintptr_t MouseIcon = 176;
    }  // namespace ClickDetector

    namespace DragDetector
    {
        constexpr std::uintptr_t ReferenceInstance = 440;
        constexpr std::uintptr_t MaxActivationDistance = 208;
        constexpr std::uintptr_t MaxDragAngle = 624;
        constexpr std::uintptr_t MaxDragTranslation = 564;
        constexpr std::uintptr_t MinDragAngle = 636;
        constexpr std::uintptr_t MinDragTranslation = 576;
        constexpr std::uintptr_t ActivatedCursorIcon = 392;
        constexpr std::uintptr_t CursorIcon = 176;
        constexpr std::uintptr_t MaxForce = 628;
        constexpr std::uintptr_t MaxTorque = 632;
        constexpr std::uintptr_t Responsiveness = 648;
    }  // namespace DragDetector

    namespace AnimationTrack
    {
        constexpr std::uintptr_t Animation = 160;
        constexpr std::uintptr_t Animator = 248;
        constexpr std::uintptr_t Speed = 188;
        constexpr std::uintptr_t TimePosition = 192;
        constexpr std::uintptr_t Looped = 205;
        constexpr std::uintptr_t IsPlaying = 2624;
    }  // namespace AnimationTrack

    namespace Animator
    {
        constexpr std::uintptr_t ActiveAnimations = 2336;
    }

    namespace LocalScript
    {
        constexpr std::uintptr_t GUID = 184;
        constexpr std::uintptr_t Hash = 392;
        constexpr std::uintptr_t ByteCode = 0;
    }  // namespace LocalScript

    namespace ByteCode
    {
        constexpr std::uintptr_t Size = 40;
        constexpr std::uintptr_t Pointer = 24;
    }  // namespace ByteCode

    namespace Script
    {
        constexpr std::uintptr_t GUID = 184;
        constexpr std::uintptr_t Hash = 392;
        constexpr std::uintptr_t ByteCode = 0;
    }  // namespace Script

    namespace MeshContentProvider
    {
        constexpr std::uintptr_t LRUHolder = 192;
    }

    namespace LRUHolder
    {
        constexpr std::uintptr_t MemEnforcedLRUCache = 32;
    }

    namespace MemEnforcedLRUCache
    {
        constexpr std::uintptr_t Head = 8;
    }

    namespace LRUNode
    {
        constexpr std::uintptr_t Next = 0;
        constexpr std::uintptr_t AssetID = 16;
        constexpr std::uintptr_t CachedItem = 56;
    }  // namespace LRUNode

    namespace CachedItem
    {
        constexpr std::uintptr_t FileMeshData = 40;
    }

    namespace FileMeshData
    {
        constexpr std::uintptr_t AABBMin = 384;
        constexpr std::uintptr_t AABBMax = 396;
        constexpr std::uintptr_t Vertices = 0;
        constexpr std::uintptr_t VerticesEnd = 8;
        constexpr std::uintptr_t Faces = 48;
        constexpr std::uintptr_t FacesEnd = 56;
    }  // namespace FileMeshData
}  // namespace Offsets