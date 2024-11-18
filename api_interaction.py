#Now that we found all of the networks ids, we can begin our get request for the montreal BIXI Bikes one
import requests
# API URL
url = "https://api.citybik.es/v2/networks/bixi-montreal"

def mtl_stations():
    #API request
    response = requests.get(url)
    #checks for status code that lets us know the api is responding
    if response.status_code == 200:
        data = response.json()
        #checks for stations in the data
        if "stations" in data["network"]:
            return data["network"]["stations"]
    return None
#Print the first line for testing
# If the algorithm recognizes a station, we have data
if __name__ == "__main__":
    stations = mtl_stations()
    if stations:
        #choosing the 1st index only
        first_station = stations[0]
        print(f"Line 1 data: {first_station}")
    else:
        print(f"Bricked.")

