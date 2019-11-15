# Projeto Plataforms Multiplayer Unreal 4.23 C++

## Preparando o projeto no drive D:
> Utilize PowerShell

    mkdir -p D:\UnrealProjects  
    git clone https://github.com/myerco/ProjetoMP.git
    cd ProjetoMP
    git status

## Atualizando o projeto no servidor
    git add .
    git commit -m "Atualizando o projeto.. Alteração de movimentação de personagem"
    git push origin master

## Atulizando o projeto no cliente (local)
    git status
    git pull origin master

## Softwares adicionais
1. **Hamachi**: Para criar uma rede privada VPN.

## Executando o projeto multiplayer
1. Cliente
    & "C:\Program Files\Epic Games\UE_4.23\Engine\Binaries\Win64\UE4Editor.exe" "D:\UnrealProjects\TaoMpCpp\TaoMpCpp.uproject" /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap -server -log
2. Servidor  
    & "C:\Program Files\Epic Games\UE_4.23\Engine\Binaries\Win64\UE4Editor.exe" "D:\UnrealProjects\TaoMpCpp\TaoMpCpp.uproject" 192.168.0.148 -game -log

## Configuração do personagem base
* Charecter Movement: Jumping/Falling

