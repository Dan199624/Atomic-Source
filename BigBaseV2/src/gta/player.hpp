#pragma once
#include <cstdint>
#include "fwddec.hpp"
#include "extensible.hpp"
#include "vector.hpp"
#include "gta\natives.hpp"
#include "../rlGamerInfo.hpp"
#include "../rlSessionInfo.hpp"
#pragma pack(push, 1)
namespace rage
{

	class netAddress
	{
	public:
		uint8_t m_field4; //0x0000
		uint8_t m_field3; //0x0001
		uint8_t m_field2; //0x0002
		uint8_t m_field1; //0x0003
	}; //Size: 0x0004
	static_assert(sizeof(netAddress) == 0x4);

	class netPlayerData
	{
	public:
		char pad_0000[8]; //0x0000
		uint64_t m_rockstar_id; //0x0008
		char pad_0010[52]; //0x0010
		class netAddress m_relay_ip; //0x0044
		uint16_t m_relay_port; //0x0048
		char pad_004A[2]; //0x004A
		class netAddress m_external_ip; //0x004C
		uint16_t m_external_port; //0x0050
		char pad_0052[2]; //0x0052
		class netAddress m_internal_ip; //0x0054
		uint16_t m_internal_port; //0x0058
		char pad_005A[6]; //0x005A
		uint64_t m_host_token; //0x0060
		uint64_t m_peer_id; //0x0068
		uint64_t m_rockstar_id2; //0x0070
		char pad_0078[12]; //0x0078
		char m_name[20]; //0x0084



	}; //Size: 0x0098
	static_assert(sizeof(netPlayerData) == 0x98);

	union netIpAddress {
		uint32_t m_packed;
		struct {
			uint8_t m_field4;
			uint8_t m_field3;
			uint8_t m_field2;
			uint8_t m_field1;
		};
	};
	static_assert(sizeof(netIpAddress) == 0x04);
	class netSocketAddress {
	public:
		netIpAddress m_ip;
		uint16_t m_port;
	};
	class rlGamerId {
	public:
		rlGamerId() = default;
		rlGamerId(uint64_t accountId) : m_account_id(accountId) {}
		uint64_t m_account_id = 0; //0x0000
		uint8_t m_unk = 3; //0x0008
		char m_pad1[0x07]{}; //0x0009
	};

	class nonPhysicalPlayerDataBase
	{
	public:
		virtual ~nonPhysicalPlayerDataBase();
		virtual void read();
		virtual void write();
		virtual void calculate_size();
		virtual void log();
	}; //Size: 0x0008
	static_assert(sizeof(nonPhysicalPlayerDataBase) == 0x8);
#pragma pack(push, 4)
	class CNonPhysicalPlayerData : public rage::nonPhysicalPlayerDataBase
	{
	public:
		int32_t m_bubble_id; //0x0008
		int32_t m_player_id; //0x000C
		rage::fvector3 m_position; //0x0010
	}; //Size: 0x001C
	static_assert(sizeof(CNonPhysicalPlayerData) == 0x1C);
#pragma pack(pop)

#pragma pack(push, 8)
	class netPlayer
	{
	public:
		virtual ~netPlayer();
		virtual void reset();
		virtual bool is_valid();
		virtual const char* get_name();
		virtual void _0x20();
		virtual bool is_host();
		virtual rage::rlGamerInfo* get_net_data();
		virtual void _0x38();

		char pad_0008[8]; //0x0008
		CNonPhysicalPlayerData* m_non_physical_player; //0x0010
		uint32_t m_msg_id; //0x0018
		char pad_001C[4]; //0x001C
		uint8_t m_active_id; //0x0020
		uint8_t m_player_id; //0x0021
		char pad_0022[3]; //0x0022
		uint16_t m_complaints; //0x0026
		char pad_0027[17]; //0x0028
		class CNetGamePlayer* m_unk_net_player_list[10]; //0x0040
		char pad_0090[4]; //0x0090
		uint64_t pad_0098; //0x0098
	}; //Size: 0x00A0
	static_assert(sizeof(netPlayer) == 0xA0);
#pragma pack(pop)


}

namespace gta
{
	inline constexpr auto num_players = 32;
}


#pragma pack(push, 1)
class ClanData
{
public:
	int64_t m_clan_member_id; //0x0000
	int64_t m_clan_id; //0x0008
	int32_t m_clan_color; //0x0010
	int32_t m_clan_member_count; //0x0014
	int32_t m_clan_created_time; //0x0018
	bool m_is_system_clan; //0x001C
	bool m_is_clan_open; //0x001D
	char m_clan_name[25]; //0x001E
	char m_clan_tag[5]; //0x0037
	char m_clan_motto[65]; //0x003C
	char pad_007D[3]; //0x007D
	int64_t m_clan_id_2; //0x0080
	char m_clan_rank_name[25]; //0x0088
	char pad_00A1[3]; //0x00A1
	int32_t m_clan_rank_order; //0x00A4
	int64_t m_clan_rank_flags; //0x00A8
	char unk_00B0[8]; //0x00B0
};
#pragma pack(pop)

#pragma pack(push, 8)
class CNetGamePlayer : public rage::netPlayer
{
public:
	CPlayerInfo* m_player_info; //0x00A0
	uint32_t m_matchmaking_group; //0x0008
	bool m_is_spectating; //0x000C
	char pad_00AD[3]; //0x000AD
	uint64_t unk_00B0; //0x00B0
	char unk_00B8; //0x00B8
	char pad_00B9[3]; //0x00B9
	uint32_t unk_00BC; //0x00BC
	uint32_t unk_00C0; //0x00C0
	char pad_00C4[4]; //0x00C4
	ClanData m_clan_data; //0x00C8
	char m_crew_rank_title[25]; //0x0180
	bool m_is_rockstar_dev; //0x0199
	bool m_is_rockstar_qa; //0x019A
	bool m_is_cheater; //0x019B
	uint32_t unk_019C; //0x019C
	uint16_t unk_01A0; //0x01A0
	char unk_01A2; //0x01A2
	char pad_01A3; //0x01A3
	uint32_t m_phone_explosion_vehicle_net_id; //0x01A4
	uint16_t unk_01A8; //0x01A8
	bool m_has_started_transition; //0x01AA
	char pad_01AB[5]; //0x01AB
	rage::rlSessionInfo m_transition_session_info; //0x01A3
	char pad_022D[16]; //0x022D
	uint64_t unk_0230; //0x0230
	uint64_t unk_0238; //0x0238
	uint32_t m_mute_count; //0x0240
	uint32_t m_mute_talkers_count; //0x0244
	char pad_0248[5]; //0x0248
	bool m_have_communication_privileges; //0x024D
	uint16_t unk_024E; //0x024E
	uint16_t unk_0250; //0x0250
	char pad_0252[2]; //0x0252
	uint32_t m_cheat_report_ids[20]; //0x0254
	uint32_t m_num_cheat_reports; //0x02A4
	uint8_t unk_02A8; //0x02A8
	char pad_02A9[3]; //0x02A9
	uint32_t unk_02AC; //0x02AC
	char unk_02B0; //0x02B0
	char pad_02B1[3]; //0x02B1
	uint32_t unk_02B4; //0x02B4
	uint32_t m_account_id; //0x02B4
	uint32_t m_unk_02BC; //0x02BC
}; //Size: 0x02C0
static_assert(sizeof(CNetGamePlayer) == 0x2C0);
#pragma pack(pop)

enum class eGameState : int32_t
{
	Invalid = -1,
	Playing,
	Died,
	Arrested,
	FailedMission,
	LeftGame,
	Respawn,
	InMPCutscene
};


struct PlayerInfo_s
{


	int IP[4] = { 0,0,0,0 };
	std::string IPString;
	nlohmann::json ip_data;
	bool IPDataCompleted = false;

}; inline PlayerInfo_s m_player_info;
class CPlayerInfo
{
public:
	char pad_0000[32]; //0x0000
	class rage::netPlayerData m_net_player_data; //0x0020
	char pad_00B8[184]; //0x00B8
	float m_swim_speed; //0x0170
	char pad_0174[20]; //0x0174
	uint32_t m_water_proof; //0x0188
	char pad_018C[76]; //0x018C
	eGameState m_game_state; //0x01D8
	char pad_01DC[12]; //0x01DC
	class CPed* m_ped; //0x01E8
	char pad_01F0[40]; //0x01F0
	uint32_t m_frame_flags; //0x0218
	char pad_021C[52]; //0x021C
	uint32_t m_player_controls; //0x0250
	char pad_0254[1256]; //0x0254
	float m_wanted_can_change; //0x073C
	char pad_0740[304]; //0x0740
	uint32_t m_npc_ignore; //0x0870
	char pad_0874[12]; //0x0874
	bool m_is_wanted; //0x0880
	char pad_0881[7]; //0x0881
	uint32_t m_wanted_level; //0x0888
	uint32_t m_wanted_level_display; //0x088C
	char pad_0890[1120]; //0x0890
	float m_run_speed; //0x0CF0
	float m_stamina; //0x0CF4
	float m_stamina_regen; //0x0CF8
	char pad_0CFC[16]; //0x0CFC
	float m_weapon_damage_mult; //0x0D0C
	float m_weapon_defence_mult; //0x0D10
	char pad_0D14[4]; //0x0D14
	float m_melee_weapon_damage_mult; //0x0D18
	float m_melee_damage_mult; //0x0D1C
	float m_melee_defence_mult; //0x0D20
	char pad_0D24[8]; //0x0D24
	float m_melee_weapon_defence_mult; //0x0D2C
}; //Size: 0x0D30
static_assert(sizeof(CPlayerInfo) == 0xD30);
//static_assert(sizeof(CNonPhysicalPlayerData) == 0x1C);
#pragma pack(pop)


namespace rage
{

	class netPlayerMgrBase
	{
	public:
		virtual ~netPlayerMgrBase() = default;
		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void unk_0x18() = 0;
		virtual CNetGamePlayer* AddPlayer_raw(void* a1, void* a2, void* a3, rage::netPlayerData* net_player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
		virtual void RemovePlayer(CNetGamePlayer* net_game_player) = 0;
		virtual void UpdatePlayerListsForPlayer(CNetGamePlayer* net_game_player) = 0;
		virtual CNetGamePlayer* AddPlayer(void* a1, void* a2, void* a3, rage::netPlayerData* net_player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
	}; //Size: 0x0008
	static_assert(sizeof(netPlayerMgrBase) == 0x8);
}

#pragma pack(push, 2)
class CNetworkPlayerMgr : public rage::netPlayerMgrBase
{
public:
	char pad_0008[224]; //0x0008
	class CNetGamePlayer* m_local_net_player; //0x00E8
	char pad_00F0[144]; //0x00F0
	class CNetGamePlayer* m_player_list[32]; //0x0180
	uint16_t m_player_limit; //0x0280
	char pad_0282[10]; //0x0282
	uint16_t m_player_count; //0x028C
}; //Size: 0x028E
static_assert(sizeof(CNetworkPlayerMgr) == 0x28E);
#pragma pack(pop)

