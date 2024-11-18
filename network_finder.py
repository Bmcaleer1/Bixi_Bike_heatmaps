import requests
#API URl
network_url = "http://api.citybik.es/v2/networks"

def get_networks():
    # Get req
    response = requests.get(network_url)
    #status code lets us know that the API is live
    if response.status_code == 200:
        data = response.json()
        networks = data.get("networks", [])
        # parse through data
        network_info = [(network["name"], network["location"]["city"]) for network in networks]
        return network_info
    else:
        print(f"Bricked Status code: {response.status_code}")
        return []

if __name__ == "__main__":
    network_info = get_networks()
    if network_info:
        print("Network names/cities:")
        for name, city in network_info:
            #output
            print(f"{name} - {city}")
    else:
        print("No networks???")